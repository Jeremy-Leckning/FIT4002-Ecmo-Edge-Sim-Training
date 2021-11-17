/* Distributed under the Apache License, Version 2.0.
See accompanying NOTICE file for details.*/

#pragma once
#include "properties/SEProperty.h"

#define ZERO_APPROX 1e-10

class CDM_DECL SEScalarProperty
{
public:
  SEScalarProperty(std::string n, double v, std::string u)
  {
    name  = n;
    value = v;
    unit  = u;
  }
  ~SEScalarProperty() = default;

  std::string name;
  double      value;
  std::string unit;
};

class CDM_DECL NoUnit
{
public:
  NoUnit() {}
  virtual ~NoUnit() {}

  static const NoUnit unitless;
};

class CDM_DECL SEScalar : public SEProperty
{
  friend class PBProperty;//friend the serialization class
protected:
  double m_value;

  bool   m_isnan;
  bool   m_isinf;
  bool   m_readOnly;

public:
  SEScalar();
  virtual ~SEScalar();

  virtual void Clear();
  /**
  Sets the value to NaN and removes the unit
  Note that this does not affect bounds
  */
  virtual void Invalidate();

  /**
  * Copies ONLY the value and unit
  * ONLY if the provided scalar is valid.
  */
  bool Set(const SEScalar& s);

  /**
  * Copies the entire contents
  * of the provided scalar to this.
  * Even if s is invalid.
  */
  void Copy(const SEScalar& s);

  virtual bool IsValid() const;
  bool IsInfinity() const { return m_isinf; }

  bool IsPositive() const;
  bool IsNegative() const;
  bool IsZero(double limit = ZERO_APPROX) const;

  void SetReadOnly(bool b);
  bool IsReadOnly() const;

  double GetValue() const;
  void   SetValue(double d);
  void   ForceValue(double d);

  double Increment(const SEScalar& s);
  double IncrementValue(double d);

  double Multiply(const SEScalar& s);
  double MultiplyValue(double d);

  void Average(int cnt);

  bool Equals(const SEScalar& to) const;

  virtual std::string ToString() const;
  virtual void ToString(std::ostream &str) const;

  static double dNaN();
  static unsigned long long int NaN;
  static bool IsNumber(double d);
  static bool IsZero(double value, double limit);
  static bool IsValue(double target, double value);
};

inline std::ostream& operator<< (std::ostream& out, const SEScalar* s)
{
  if (s == nullptr)
    out << SEScalar::NaN << std::flush;
  else
    (*s).ToString(out);
  return out;
}
inline std::ostream& operator<< (std::ostream& out, const SEScalar& s)
{
  s.ToString(out);
  return out;
}

template <typename Enum>
class CDM_DECL SEScalarEnum : public SEScalar
{
public:
  SEScalarEnum() : SEScalar() { Clear(); }
  virtual ~SEScalarEnum() { Clear(); }

  virtual void Invalidate()
  {
    SEScalar::Invalidate();
    m_enum = (Enum)-1;
  }
  bool Set(const SEScalarEnum<Enum>& s)
  {
    SEScalar::Set(s);
    m_enum = s.m_enum;
  }
  void Copy(const SEScalarEnum<Enum>& s)
  {
    SEScalar::Set(s);
    m_enum = s.m_enum;
  }

  Enum GetEnum() const { return m_enum; }
  void SetEnum(Enum e)
  {
    m_enum = e;
    SetValue((double)e);
  }

private:
  using SEScalar::IsInfinity;

  using SEScalar::IsPositive;
  using SEScalar::IsNegative;
  using SEScalar::IsZero;

  using SEScalar::SetValue;
  using SEScalar::ForceValue;

  using SEScalar::Increment;
  using SEScalar::IncrementValue;

  using SEScalar::Multiply;
  using SEScalar::MultiplyValue;

  using SEScalar::Average;

protected:
  Enum m_enum;
};

/**
* @brief - An interface to be used for gaining access to a scalar with any unit type
* @details - This interface allows you to have a pointer to a scalar with units
*            but you don't need to now what units it's associated with
*/
class CDM_DECL SEUnitScalar : public SEScalar
{
  friend class PBProperty;//friend the serialization class
  friend SEGenericScalar;
public:

  SEUnitScalar() : SEScalar() {}
  virtual ~SEUnitScalar() {}

  virtual bool IsValid() const = 0;
  virtual void Invalidate() = 0;
  virtual bool HasUnit() const = 0;
  virtual const CCompoundUnit* GetUnit() const = 0;

  virtual bool Set(const SEScalar& s) = 0;
  virtual void Copy(const SEScalar& s) = 0;
  virtual double GetValue(const CCompoundUnit& unit) const = 0;
  virtual void   SetValue(double d, const CCompoundUnit& unit) = 0;
  virtual void   ForceValue(double d, const CCompoundUnit& unit) = 0;
  virtual double IncrementValue(double d, const CCompoundUnit& unit) = 0;
  virtual double MultiplyValue(double d, const CCompoundUnit& unit) = 0;

protected:
  virtual const CCompoundUnit* GetCompoundUnit(const std::string& unit) const = 0;
};

template <typename Unit>
class SEScalarQuantity : public SEUnitScalar
{
  friend class PBProperty;//friend the serialization class
public:
  SEScalarQuantity();
  virtual ~SEScalarQuantity();

  virtual void Clear();
  virtual void Invalidate();
  virtual bool IsValid() const;

protected:

  // We need to support the SEUnitScalar interface,  but make these protected
  // If you want access in a generic unit way, us an SEGenericScalar wrapper
  bool Set(const SEScalar& s);
  void Copy(const SEScalar& s);

  virtual double GetValue(const CCompoundUnit& unit) const;
  virtual void   SetValue(double d, const CCompoundUnit& unit);
  virtual void   ForceValue(double d, const CCompoundUnit& unit);
  virtual double IncrementValue(double d, const CCompoundUnit& unit);
  virtual double MultiplyValue(double d, const CCompoundUnit& unit);

  virtual const CCompoundUnit* GetCompoundUnit(const std::string& unit) const;

public:

  virtual bool Set(const SEScalarQuantity<Unit>& s);
  virtual void Copy(const SEScalarQuantity<Unit>& s);

  virtual bool HasUnit() const;
  virtual const Unit* GetUnit() const;

  double GetValue() const = delete;// Must provide a unit
  virtual double GetValue(const Unit& unit) const;

  void SetValue(double d) = delete;// Must provide a unit
  virtual void SetValue(double d, const Unit& unit);

  void ForceValue(double d) = delete;// Must provide a unit
  virtual void ForceValue(double d, const Unit& unit);

  double IncrementValue(double d) = delete;// Must provide a unit
  virtual double IncrementValue(double d, const Unit& unit);

  double Increment(const SEScalar& s) = delete;// Must provide a unit
  virtual double Increment(const SEScalarQuantity& s);

  double MultiplyValue(double d) = delete;// Must provide a unit
  virtual double MultiplyValue(double d, const Unit& unit);

  double Multiply(const SEScalar& s) = delete;// Must provide a unit
  virtual double Multiply(const SEScalarQuantity& s);

  bool Equals(const SEScalar& to) const = delete;// Must provide a unit
  virtual bool Equals(const SEScalarQuantity<Unit>& to) const;

  virtual std::string ToString() const;
  virtual void ToString(std::ostream &str) const;

protected:
  const Unit* m_unit;
};


// I created this class for use in connecting DataRequests to SEScalars for the PhysiologyEngineTrack class
/**
* @brief If you want to querry what a scalar is and don't know what scalar type you have...
* @details Be aware, I did not really protect this class, I assume you know what you are doing
* If you use this class without setting the scalar it will produce nullptr errors and other CDM Exceptions, use with caution and smarts.
*/
class CDM_DECL SEGenericScalar : public Loggable
{
  friend class PBProperty;//friend the serialization class
public:
  SEGenericScalar(Logger* logger);
  virtual ~SEGenericScalar() {};

  virtual bool HasScalar() const;
  virtual void SetScalar(const SEScalar& s);

  virtual bool IsValid() const;
  virtual bool IsInfinity() const;

  virtual bool HasUnit() const;
  virtual const CCompoundUnit* GetUnit() const;
  virtual bool IsValidUnit(const CCompoundUnit& unit) const;
  virtual const CCompoundUnit* GetCompoundUnit(const std::string& unit) const;

  virtual double GetValue() const;
  virtual double GetValue(const CCompoundUnit& unit) const;

protected:

  const SEScalar*     m_Scalar;
  const SEUnitScalar* m_UnitScalar;
};

inline void Override(const SEScalar& from, SEScalar& to)
{
  bool b = to.IsReadOnly();
  to.SetReadOnly(false);
  to.Set(from);
  to.SetReadOnly(b);
}
template<class Unit>
inline void Override(const SEScalarQuantity<Unit>& from, SEScalarQuantity<Unit>& to)
{
  bool b = to.IsReadOnly();
  to.SetReadOnly(false);
  to.Set(from);
  to.SetReadOnly(b);
}

inline void ValueOverride(SEScalar& s, double value)
{
  bool b = s.IsReadOnly();
  s.SetReadOnly(false);
  s.SetValue(value);
  s.SetReadOnly(b);
}
template<class Unit>
inline void ValueOverride(SEScalarQuantity<Unit>& s, double value, const Unit& unit)
{
  bool b = s.IsReadOnly();
  s.SetReadOnly(false);
  s.SetValue(value, unit);
  s.SetReadOnly(b);
}

inline void IncrementOverride(SEScalar& s, double value)
{
  bool b = s.IsReadOnly();
  s.SetReadOnly(false);
  s.IncrementValue(value);
  s.SetReadOnly(b);
}
template<class Unit>
inline void IncrementOverride(SEScalarQuantity<Unit>& s, double value, const Unit& unit)
{
  bool b = s.IsReadOnly();
  s.SetReadOnly(false);
  s.IncrementValue(value, unit);
  s.SetReadOnly(b);
}

#define DEFINE_SCALAR_PTR(name, type) \
  public: \
    bool Has##name() const \
    { \
      return m_##name==nullptr?false:m_##name->IsValid(); \
    } \
    SEScalar##type& Get##name() \
    { \
      if(m_##name==nullptr) \
        m_##name = new SE##type(); \
      return *m_##name; \
    } \
    double Get##name() const \
    { \
      if (m_##name == nullptr) \
        return SEScalar::dNaN(); \
      return m_##name->GetValue(); \
    } \
  protected: \
    SEScalar##type m_##name;

#define DEFINE_UNIT_SCALAR_PTR(name, type) \
  public: \
    bool Has##name() const \
    { \
      return m_##name==nullptr?false:m_##name->IsValid(); \
    } \
    SEScalar##type& Get##name() \
    { \
      if(m_##name==nullptr) \
        m_##name = new SE##type(); \
      return *m_##name; \
    } \
    double Get##name(const type##Unit& unit) const \
    { \
      if (m_##name == nullptr) \
        return SEScalar::dNaN(); \
      return m_##name->GetValue(unit); \
    } \
  protected: \
    SEScalar##type m_##name;

#define DEFINE_SCALAR(name, type) \
  public: \
    bool Has##name() const { return m_##name.IsValid(); } \
    SEScalar##type& Get##name() { return m_##name; } \
    double Get##name() const { return m_##name.GetValue(); } \
  protected: \
    SEScalar##type m_##name;

#define DEFINE_UNIT_SCALAR(name, type) \
  public: \
    bool Has##name() const { return m_##name.IsValid(); } \
    SEScalar##type& Get##name() { return m_##name; } \
    double Get##name(const type##Unit& unit) const { return m_##name.GetValue(unit); } \
  protected: \
    SEScalar##type m_##name;

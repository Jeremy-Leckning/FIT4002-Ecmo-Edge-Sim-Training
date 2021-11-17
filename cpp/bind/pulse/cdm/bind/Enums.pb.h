// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: pulse/cdm/bind/Enums.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_pulse_2fcdm_2fbind_2fEnums_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_pulse_2fcdm_2fbind_2fEnums_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3014000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3014000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_pulse_2fcdm_2fbind_2fEnums_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_pulse_2fcdm_2fbind_2fEnums_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_pulse_2fcdm_2fbind_2fEnums_2eproto;
PROTOBUF_NAMESPACE_OPEN
PROTOBUF_NAMESPACE_CLOSE
namespace pulse {
namespace cdm {
namespace bind {

enum eSide : int {
  NullSide = 0,
  Left = 1,
  Right = 2,
  eSide_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  eSide_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool eSide_IsValid(int value);
constexpr eSide eSide_MIN = NullSide;
constexpr eSide eSide_MAX = Right;
constexpr int eSide_ARRAYSIZE = eSide_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* eSide_descriptor();
template<typename T>
inline const std::string& eSide_Name(T enum_t_value) {
  static_assert(::std::is_same<T, eSide>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function eSide_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    eSide_descriptor(), enum_t_value);
}
inline bool eSide_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, eSide* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<eSide>(
    eSide_descriptor(), name, value);
}
enum eGate : int {
  NullGate = 0,
  Open = 1,
  Closed = 2,
  eGate_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  eGate_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool eGate_IsValid(int value);
constexpr eGate eGate_MIN = NullGate;
constexpr eGate eGate_MAX = Closed;
constexpr int eGate_ARRAYSIZE = eGate_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* eGate_descriptor();
template<typename T>
inline const std::string& eGate_Name(T enum_t_value) {
  static_assert(::std::is_same<T, eGate>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function eGate_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    eGate_descriptor(), enum_t_value);
}
inline bool eGate_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, eGate* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<eGate>(
    eGate_descriptor(), name, value);
}
enum eSwitch : int {
  NullSwitch = 0,
  Off = 1,
  On = 2,
  eSwitch_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  eSwitch_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool eSwitch_IsValid(int value);
constexpr eSwitch eSwitch_MIN = NullSwitch;
constexpr eSwitch eSwitch_MAX = On;
constexpr int eSwitch_ARRAYSIZE = eSwitch_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* eSwitch_descriptor();
template<typename T>
inline const std::string& eSwitch_Name(T enum_t_value) {
  static_assert(::std::is_same<T, eSwitch>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function eSwitch_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    eSwitch_descriptor(), enum_t_value);
}
inline bool eSwitch_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, eSwitch* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<eSwitch>(
    eSwitch_descriptor(), name, value);
}
enum eCharge : int {
  NullCharge = 0,
  Negative = 1,
  Neutral = 2,
  Positive = 3,
  eCharge_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  eCharge_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool eCharge_IsValid(int value);
constexpr eCharge eCharge_MIN = NullCharge;
constexpr eCharge eCharge_MAX = Positive;
constexpr int eCharge_ARRAYSIZE = eCharge_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* eCharge_descriptor();
template<typename T>
inline const std::string& eCharge_Name(T enum_t_value) {
  static_assert(::std::is_same<T, eCharge>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function eCharge_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    eCharge_descriptor(), enum_t_value);
}
inline bool eCharge_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, eCharge* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<eCharge>(
    eCharge_descriptor(), name, value);
}
// ===================================================================


// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace bind
}  // namespace cdm
}  // namespace pulse

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::pulse::cdm::bind::eSide> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::pulse::cdm::bind::eSide>() {
  return ::pulse::cdm::bind::eSide_descriptor();
}
template <> struct is_proto_enum< ::pulse::cdm::bind::eGate> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::pulse::cdm::bind::eGate>() {
  return ::pulse::cdm::bind::eGate_descriptor();
}
template <> struct is_proto_enum< ::pulse::cdm::bind::eSwitch> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::pulse::cdm::bind::eSwitch>() {
  return ::pulse::cdm::bind::eSwitch_descriptor();
}
template <> struct is_proto_enum< ::pulse::cdm::bind::eCharge> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::pulse::cdm::bind::eCharge>() {
  return ::pulse::cdm::bind::eCharge_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_pulse_2fcdm_2fbind_2fEnums_2eproto

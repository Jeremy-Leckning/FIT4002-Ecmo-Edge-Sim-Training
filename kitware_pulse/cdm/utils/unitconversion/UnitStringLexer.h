/* Distributed under the Apache License, Version 2.0.
   See accompanying NOTICE file for details.*/

//----------------------------------------------------------------------------
/// @file UnitStringLexer.h
/// @author Chris Volpe
/// 
/// This class implements a lexical analyzer for the parser inside CompoundUnit
/// that parses a complex unit string
//----------------------------------------------------------------------------
#pragma once

#if defined(_MSC_VER)
  // Note: See top of CompoundUnit.h for a discussion of the lines below which export STL
  // container instantiations. In this particular case, the compiler complains about the member
  // variables "end" and "cursor". Note that exporting the iterator base must be done before
  // exporting the iterator template itself.
  #pragma warning(disable:4231)
#endif


struct SUnitStringToken
{
  SUnitStringToken()
    :tokenID(TT_ERR), symbol(), fltval(0.0)
  {
  }
  SUnitStringToken(SUnitStringToken &src)
    :tokenID(src.tokenID), symbol(src.symbol), fltval(src.fltval)
  {
  }
  std::string toString() const
  {
    switch (tokenID)
    {
    case TT_IDENTIFIER:
      return "TT_IDENTIFIER";
      break;

    case TT_EXPONENT:
      return "TT_EXPONENT";
      break;

    case TT_FLOAT:
      return "TT_FLOAT";
      break;

    case TT_SLASH:
      return "TT_SLASH";
      break;

    case TT_PARENOPEN:
      return "TT_PARENOPEN";
      break;

    case TT_PARENCLOSE:
      return "TT_PARENCLOSE";
      break;

    case TT_ERR:
      return "TT_ERR";
      break;

    case TT_EOF:
      return "TT_EOF";
      break;

    default:
      return "UNDEFINED";

    } // switch
  } // toString

  // Enumerate the various Token Types
  enum {TT_IDENTIFIER, TT_EXPONENT, TT_FLOAT, TT_SLASH, TT_PARENOPEN, TT_PARENCLOSE, TT_DB, TT_ERR, TT_EOF} tokenID;
  std::string symbol;
  double fltval;
};

class CUnitStringLexer
{
public:
  CUnitStringLexer(const std::string &src)
    :source(src), scanNext(true), end(source.end()), cursor(source.begin())
  {
    // Nothing else to do
  }

  void GetNextToken(SUnitStringToken &token)
  {
    if (scanNext)
    {
      ScanNextToken();
    }
    token = curToken;
    scanNext = true;
  }

  void PeekNextToken(SUnitStringToken &token)
  {
    if (scanNext)
    {
      ScanNextToken();
    }
    token = curToken;
    scanNext = false;
  }

protected:
  void ScanNextToken();
private:
  CUnitStringLexer();

  std::string source;
  SUnitStringToken curToken;
  bool scanNext; // Determines whether a call to PeekNextToken or GetNextToken needs to scan
  std::string::iterator end;
  std::string::iterator cursor; // current position in source string
};
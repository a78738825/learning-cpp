// ============================================================
// example_header.h
// This file exists to explain what C++ header files are
// and how they are traditionally protected from being
// included multiple times.
// ============================================================

// ------------------------------------------------------------
// MODERN WAY (preferred today)
// ------------------------------------------------------------
// #pragma once tells the compiler:
// "Include this header only once in a single compilation."
//
// It is simple, clean, and widely supported by modern compilers.
#pragma once

// ------------------------------------------------------------
// ANCIENT WAY (still valid and very common)
// ------------------------------------------------------------
// Before #pragma once became popular, programmers used
// include guards made from preprocessor macros.
//
// They look scary at first, but they are just checks.
//
// IMPORTANT:
// You normally use EITHER #pragma once OR include guards,
// not both at the same time.
// ------------------------------------------------------------

/*
#ifndef EXAMPLE_HEADER_H
#define EXAMPLE_HEADER_H

// Everything inside these lines will only be included once

#endif // EXAMPLE_HEADER_H
*/

// ------------------------------------------------------------
// WHAT GOES INSIDE A HEADER FILE?
// ------------------------------------------------------------
// Header files usually contain:
// - function declarations
// - class declarations
// - constants
// - type definitions
//
// They usually do NOT contain full function implementations
// (except for templates or very small inline functions).
// ------------------------------------------------------------

// A constant declaration
const int MAX_SCORE = 100;

// A function declaration (no body here. The actual body exists in some other
// cpp file)
void sayHello();

// A simple class declaration
class Player {
  public:
    Player(const char *name);
    void printName() const;

  private:
    const char *m_name;
};

// ------------------------------------------------------------
// WHY HEADER FILES EXIST
// ------------------------------------------------------------
// Header files allow different .cpp files to:
// - know about functions and classes
// - share declarations without duplicating code
//
// Think of a header as a "promise":
// "These things exist somewhere. You can use them."
// The actual code usually lives in a .cpp file.
// ------------------------------------------------------------

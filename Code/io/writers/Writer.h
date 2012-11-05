// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_IO_WRITERS_WRITER_H
#define HEMELB_IO_WRITERS_WRITER_H
#include <stdint.h>
#include <string>

namespace hemelb
{
  namespace io
  {
    namespace writers
    {

      class Writer
      {
        public:

          enum Separator
          {
            eol
          };

          // Special version for eol, using function overloading
          Writer& operator<<(enum Separator const & value);

          // Overload << to write basic types and any necessary separators
          template<typename T>
          Writer& operator<<(T const & value)
          {
            _write(value);
            writeFieldSeparator();
            return *this;
          }

          // Function to get the current position of writing in the stream.
          virtual unsigned int getCurrentStreamPosition() const = 0;

        protected:
          Writer();
          virtual ~Writer() =0;

          // Functions for formatting control
          virtual void writeFieldSeparator() = 0;
          virtual void writeRecordSeparator() = 0;

          // Methods to simply write (no separators) which are virtual and
          // hence must be overriden.
          virtual void _write(int16_t const& intToWrite) = 0;
          virtual void _write(uint16_t const& uIntToWrite) = 0;
          virtual void _write(int32_t const& intToWrite) = 0;
          virtual void _write(uint32_t const& uIntToWrite) = 0;
          virtual void _write(int64_t const& intToWrite) = 0;
          virtual void _write(uint64_t const& uIntToWrite) = 0;

          virtual void _write(double const& doubleToWrite) = 0;
          virtual void _write(float const& floatToWrite) = 0;

          virtual void _write(const std::string& floatToWrite) = 0;
      };

    /*template <>
     inline Writer& Writer::operator<< <enum Writer::Separator> (enum Writer::Separator const & value) {
     writeRecordSeparator();
     return *this;
     }*/

    } // namespace writer

  }
}

#endif // HEMELB_IO_WRITERS_WRITER_H

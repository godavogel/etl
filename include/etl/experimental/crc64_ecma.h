///\file

/******************************************************************************
The MIT License(MIT)

Embedded Template Library.
https://github.com/ETLCPP/etl
https://www.etlcpp.com

Copyright(c) 2021 jwellbelove

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
******************************************************************************/

#ifndef ETL_CRC64_ECMA_EX_INCLUDED
#define ETL_CRC64_ECMA_EX_INCLUDED

#include "../platform.h"
#include "crc_implementation.h"

#if defined(ETL_COMPILER_KEIL)
#pragma diag_suppress 1300
#endif

///\defgroup crc64_ecma 64 bit ECMA CRC calculation
///\ingroup crc

namespace etl
{
  namespace crc
  {
    template <size_t Table_Size>
    class crc64_ecma_t : public etl::private_crc::crc_type<uint64_t, 0x42F0E1EBA9EA3693U, 0x0000000000000000U, 0x0000000000000000U, false, Table_Size>
    {
    public:

      ETL_STATIC_ASSERT((Table_Size == 4U) || (Table_Size == 16U) || (Table_Size == 256U), "Table size must be 4, 16 or 256");

      //*************************************************************************
      /// Default constructor.
      //*************************************************************************
      crc64_ecma_t()
      {
        this->reset();
      }

      //*************************************************************************
      /// Constructor from range.
      /// \param begin Start of the range.
      /// \param end   End of the range.
      //*************************************************************************
      template<typename TIterator>
      crc64_ecma_t(TIterator begin, const TIterator end)
      {
        this->reset();
        this->add(begin, end);
      }
    };

    typedef etl::crc::crc64_ecma_t<256U> crc64_ecma_t256;
    typedef etl::crc::crc64_ecma_t<16U>  crc64_ecma_t16;
    typedef etl::crc::crc64_ecma_t<4U>   crc64_ecma_t4;
    typedef crc64_ecma_t256              crc64_ecma;
  }
}
#endif

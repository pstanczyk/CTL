#ifndef INCLUDED_APPLY_CTL_H
#define INCLUDED_APPLY_CTL_H

///////////////////////////////////////////////////////////////////////////////
// 
// Copyright (c) 2013 Academy of Motion Picture Arts and Sciences
// ("A.M.P.A.S."). Portions contributed by others as indicated.
// All rights reserved.
// 
// A world-wide, royalty-free, non-exclusive right to distribute, copy,
// modify, create derivatives, and use, in source and binary forms, is
// hereby granted, subject to acceptance of this license. Performance of
// any of the aforementioned acts indicates acceptance to be bound by the
// following terms and conditions:
// 
//   * Redistributions of source code, in whole or in part, must
//     retain the above copyright notice, this list of conditions and
//     the Disclaimer of Warranty.
// 
//   * Redistributions in binary form must retain the above copyright
//     notice, this list of conditions and the Disclaimer of Warranty
//     in the documentation and/or other materials provided with the
//     distribution.
// 
//   * Nothing in this license shall be deemed to grant any rights to
//     trademarks, copyrights, patents, trade secrets or any other
//     intellectual property of A.M.P.A.S. or any contributors, except
//     as expressly stated herein.  Neither the name of. A.M.P.A.S. nor
//     any other contributors to this software may be used to endorse or
//     promote products derivative or, or based on this software without
//     express prior written permission of A.M.P.A.S. or contributor, as
//     appropriate.
// 
//   * This license shall be construed pursuant to the laws of the State
//     of California, and any disputes related thereto shall be subject
//     to the jurisdiction of the courts therein.
// 
// Disclaimer of Warranty: THIS SOFTWARE IS PROVIDED BY A.M.P.A.S. AND
// CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING,
// BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT ARE DISCLAIMED. IN NO
// EVENT SHALL A.M.P.A.S., OR ANY CONTRIBUTORS OR DISTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
// RESITUTIONARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
// TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// 
///////////////////////////////////////////////////////////////////////////////

//----------------------------------------------------------------------------
//
//	Apply CTL transforms
//
//----------------------------------------------------------------------------

#include <ImfRgba.h>
#include <ImfArray.h>
#include <ImfHeader.h>
#include <ImfChromaticities.h>
#include <vector>
#include <string>
#include <map>

//
// Apply a series of CTL transforms to the pixels from an OpenEXR file
// in order to generate pixels for a new OpenEXR file.
//
//	inHeader		The header of the input OpenEXR file.
//
//	outHeader		The header for the output OpenEXR file.
//
//	inPixels		Pixels from the input OpenEXR file
//				(three channels: R, G, and B)
//
//	outPixels		Pixels for output input OpenEXR file
//				(three channels: R, G and B)
//
//	w, h			Width and height of the inPixels and outPixels
//				arrays.  (The caller must set the size of the
//				arrays to w*h, before calling applyCtl().)
//
//	transformNames		A list of the names of the CTL transforms
//				that will be applied to the input pixels.
//
//	extraAttrs		A list of attributes that will be added
//				to inHeader before the CTL transforms
//				are applied.
//			


typedef std::map <std::string, Imf::Attribute *> AttrMap;


void	applyCtlExrToExr (Imf::Header inHeader,
			  Imf::Header &outHeader,
			  const Imf::Array2D<Imf::Rgba> &inPixels,
			  Imf::Array2D<Imf::Rgba> &outPixels,
			  int w,
			  int h,
			  const std::vector<std::string> &transformNames,
			  const AttrMap &extraAttrs);

#endif

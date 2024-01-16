////////////////////////////////////////////////////////////////////////////////
// Catapult Synthesis
// 
// Copyright (c) 2003-2015 Mentor Graphics Corp.
//       All Rights Reserved
// 
// This document contains information that is proprietary to Mentor Graphics
// Corp. The original recipient of this document may duplicate this  
// document in whole or in part for internal business purposes only, provided  
// that this entire notice appears in all copies. In duplicating any part of  
// this document, the recipient agrees to make every reasonable effort to  
// prevent the unauthorized use and distribution of the proprietary information.
////////////////////////////////////////////////////////////////////////////////
// NO WARRANTY. MENTOR GRAPHICS EXPRESSLY DISCLAIMS ALL WARRANTY 
// FOR THE SOFTWARE. TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE 
// LAW, THE SOFTWARE AND ANY RELATED DOCUMENTATION IS PROVIDED "AS IS"
// AND WITH ALL FAULTS AND WITHOUT WARRANTIES OR CONDITIONS OF ANY 
// KIND, EITHER EXPRESS OR IMPLIED, INCLUDING, WITHOUT LIMITATION, THE 
// IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR 
// PURPOSE, OR NONINFRINGEMENT. THE ENTIRE RISK ARISING OUT OF USE OR 
// DISTRIBUTION OF THE SOFTWARE REMAINS WITH YOU.
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//  Source:         ac_dsp_utils.h
//  Description:    Various C++ classes used in testbenches for DSP designs
////////////////////////////////////////////////////////////////////////////////

#include <ac_channel.h>

//====================================================================
// Function: gen_random
// Description: Calculate a random number
// Return value: A random number as a double between 0 and 1
//====================================================================
inline double gen_random()
{
   return( (double)(rand() & RAND_MAX) / RAND_MAX - 0.5 );
}

//====================================================================
// Function: chirp
// Description: Generate monuaral samples of length 'length' of a 
// sinusoidal signal frequency sweep
// Return value: The number of samples created
//====================================================================
inline int chirp(int length, ac_channel<double> &samples)
{
   double interval = 2.0 * atan(1.0)/(double)length;
   for (int i=0; i<length; i++) {
      double sample = (double) sin( (double)(i * i) * interval);
      samples.write(sample);
   }
   return(length);
}

//====================================================================
// Function: gen_wave
// Description: Generates monaural sinusoidal waveform of length 
// 'samples' at frequency 'freq' (in Hz), sample frequency 'fs'
// and with amplitude 'amp'.
// Return value: The number of samples created
//====================================================================
template <class T>
inline int gen_wave(int samples, int freq, int fs, int amp, ac_channel<T> &waveout)
{
  const double twoPI = 2.0*3.14159;
  int i=0;
  for (i=0; i < samples; i++) {
    double val = ((double)amp)*sin(twoPI * freq * ((double)i/(double)fs));
    T val2 = val;
    waveout.write(val);
  }
  return i;
}

//====================================================================
// Function: gen_modulated_wave
// Description: Generates modulated monaural sinusoidal waveform of 
// length 'samples' at frequencies 'freq1' and 'freq2' (in Hz), sample
// frequency 'fs' and with amplitude 'amp'.
// Return value: The number of samples created
//====================================================================
template <class T>
inline int gen_modulated_wave(int samples, int freq1, int freq2, int fs, int amp, ac_channel<T> &waveout)
{
  const double twoPI = 2.0*3.14159;
  int i=0;
  for (i=0; i < samples; i++) {
    double val = ((double)amp)*sin(twoPI * freq1 * ((double)i/(double)fs)) + 
                 ((double)amp)*sin(twoPI * freq2 * ((double)i/(double)fs));
    T val2 = val/2.0;
    waveout.write(val);
  }
  return i;
}

//====================================================================
// Function: uniform_noise
// Description: Generate monaural samples of length 'length' of 
// uniformly distributed random numbers between 0 and 1 (uniform noise).
// Return value: The number of samples created
//====================================================================
inline int uniform_noise(int length, ac_channel<double> &samples)
{
   for (int i=0; i<length; i++) {
      double sample = gen_random();
      samples.write(sample);
   }
   return(length);
}

//====================================================================
// Function: gaussian_noise
// Description: Generate monaural samples of length 'length' of 
// Gaussian-distributed random numbers of the specified maximum
// amplitude.
// Return value: The number of samples created
//====================================================================
inline int gaussian_noise(int length, double amplitude, ac_channel<double> &samples)
{
   double v1, v2, r; 
   for (int i=0; i<length/2; i++) {
      do {
         v1 = 2.0 * gen_random();
         v2 = 2.0 * gen_random();
         r = v1 * v1 + v2 * v2;
      } while (r > 1.0);
      double fac = sqrt( 2.0 * -log(r)/r);
      samples.write(v1 * fac * amplitude);
      samples.write(v2 * fac * amplitude);
   }
   return(length);
}

//====================================================================
// Function: get_stdev
// Description: Calculates the standard deviation of the list of
// samples.
// Return value: The standard deviation (same data type as samples).
//====================================================================
template <class T>
T get_std_dev(ac_channel<T> &samples)
{
   T sum = (T)0;
   T sum2 = (T)0;
   
   for (unsigned int i=0; i<samples.debug_size(); i++) {
      T sample = samples[i];
      sum += sample;
      sum2 += sample * sample;
   }
   T avg = sum / (T)samples.debug_size();
   T var = (sum2 - sum * avg) / ( samples.debug_size() - 1);
   return(sqrt(var));   
}

//====================================================================
// Function: get_stats
// Description: Calculates various statistical measures for the specified
// samples including:
//   min - minimum value
//   max - maximum value
//   avg - average value
//   variance - variance
//   stdev - standard deviation
// Calculated values are returned in referenced arguments.
// Return value: None
//====================================================================
template <class T>
void get_stats(ac_channel<T> &samples, T& min, T& max, T& avg, T&variance, T&stdev)
{
   if (!samples.available(1)) {
      std::cerr << "get_stats: 'samples' is empty" << std::endl;
      return;
   }
   min = max = samples[0];
   T sum = (T)0;
   T sum2 = (T)0;
   
   for (unsigned int i=0; i<samples.debug_size(); i++) {
      T sample = samples[i];
      if (sample < min) min = sample;
      if (sample > max) max = sample;
      sum += sample;
      sum2 += sample * sample;
   }
   avg = sum / (T)samples.debug_size();
   variance = (sum2 - sum * avg) / ( samples.debug_size() - 1);
	stdev = sqrt(variance);
}


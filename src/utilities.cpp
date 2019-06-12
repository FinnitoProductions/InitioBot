/**
* Defines several useful utility functions which can be applied across multiply projects.
*
* @author Finn Frankis
* @since 6/12/19
*/

#include <utilities.hpp>

double Utilities::map (double val, double init_min, double init_max, double final_min, double final_max) {
   return (val - init_min) * (final_max - final_min) / (init_max - init_min) + final_min;
}
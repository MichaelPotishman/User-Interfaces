// COMP2811 Coursework 1: Quake class

#include <stdexcept>
#include "quake.hpp"

using namespace std;


Quake::Quake(const string& tm, double lat, double lon, double dep, double mag):
  time(tm), latitude(lat), longitude(lon), depth(dep), magnitude(mag)
{
  // Add validation code here

  // checking if latitude is not between acceptable values 
  if (lat < MIN_LATITUDE || lat > MAX_LATITUDE){
    throw std::invalid_argument("Latitude must be between " << MIN_LATITUDE << "and " << MAX_LATITUDE);
  }

  // checking if longitude is not between acceptable values 
  if (lon < MIN_LONGITUDE || lon > MAX_LONGITUDE){
    throw std::invalid_argument("Longitude must be between " << MIN_LONGITUDE<< "and " << MAX_LONGITUDE);
  }

  // checking if depth is negative
  if (dep < 0){
    throw std::invalid_argument("Depth cannot be negative");
  }

  // checking if magnitutde is negative
  if (dep < 0){
    throw std::invalid_argument("Magnitude cannot be negative");
  }
}


ostream& operator<<(ostream& out, const Quake& quake)
{
  return out << "Time: " << quake.getTime()
             << "\nLatitude: " << quake.getLatitude() << " deg"
             << "\nLongitude: " << quake.getLongitude() << " deg"
             << "\nDepth: " << quake.getDepth() << " km"
             << "\nMagnitude: " << quake.getMagnitude() << endl;
}

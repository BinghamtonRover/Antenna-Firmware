/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.9 */

#ifndef PB_GPS_PB_H_INCLUDED
#define PB_GPS_PB_H_INCLUDED
#include "utils/pb.h"
#include "version.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
typedef struct _GpsCoordinates {
    float latitude;
    float longitude;
    float altitude;
} GpsCoordinates;

typedef struct _Orientation {
    float x;
    float y;
    float z;
} Orientation;

typedef struct _RoverPosition {
    bool has_gps;
    GpsCoordinates gps;
    bool has_orientation;
    Orientation orientation;
    bool has_version;
    Version version;
} RoverPosition;


#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define GpsCoordinates_init_default              {0, 0, 0}
#define Orientation_init_default                 {0, 0, 0}
#define RoverPosition_init_default               {false, GpsCoordinates_init_default, false, Orientation_init_default, false, Version_init_default}
#define GpsCoordinates_init_zero                 {0, 0, 0}
#define Orientation_init_zero                    {0, 0, 0}
#define RoverPosition_init_zero                  {false, GpsCoordinates_init_zero, false, Orientation_init_zero, false, Version_init_zero}

/* Field tags (for use in manual encoding/decoding) */
#define GpsCoordinates_latitude_tag              1
#define GpsCoordinates_longitude_tag             2
#define GpsCoordinates_altitude_tag              3
#define Orientation_x_tag                        1
#define Orientation_y_tag                        2
#define Orientation_z_tag                        3
#define RoverPosition_gps_tag                    1
#define RoverPosition_orientation_tag            2
#define RoverPosition_version_tag                3

/* Struct field encoding specification for nanopb */
#define GpsCoordinates_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, FLOAT,    latitude,          1) \
X(a, STATIC,   SINGULAR, FLOAT,    longitude,         2) \
X(a, STATIC,   SINGULAR, FLOAT,    altitude,          3)
#define GpsCoordinates_CALLBACK NULL
#define GpsCoordinates_DEFAULT NULL

#define Orientation_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, FLOAT,    x,                 1) \
X(a, STATIC,   SINGULAR, FLOAT,    y,                 2) \
X(a, STATIC,   SINGULAR, FLOAT,    z,                 3)
#define Orientation_CALLBACK NULL
#define Orientation_DEFAULT NULL

#define RoverPosition_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, MESSAGE,  gps,               1) \
X(a, STATIC,   OPTIONAL, MESSAGE,  orientation,       2) \
X(a, STATIC,   OPTIONAL, MESSAGE,  version,           3)
#define RoverPosition_CALLBACK NULL
#define RoverPosition_DEFAULT NULL
#define RoverPosition_gps_MSGTYPE GpsCoordinates
#define RoverPosition_orientation_MSGTYPE Orientation
#define RoverPosition_version_MSGTYPE Version

extern const pb_msgdesc_t GpsCoordinates_msg;
extern const pb_msgdesc_t Orientation_msg;
extern const pb_msgdesc_t RoverPosition_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define GpsCoordinates_fields &GpsCoordinates_msg
#define Orientation_fields &Orientation_msg
#define RoverPosition_fields &RoverPosition_msg

/* Maximum encoded size of messages (where known) */
#define GPS_PB_H_MAX_SIZE                        RoverPosition_size
#define GpsCoordinates_size                      15
#define Orientation_size                         15
#define RoverPosition_size                       58

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
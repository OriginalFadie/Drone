#include <math.h>

struct axis_vector {
  float x_value[20];
  float y_value[20];
  float z_value[20];
};

float gyroscope_calibration(rotation_matrix, acceleration) {

  //calibrate the gyroscope to factor in gravity and the acceleration
  float gyroscope_orientation = rotation_matrix * (9.83 - acceleration);
  return gyroscope_orientation;
}

//Generates a struct using the x, y and z axis
axis_vector axis_struct(x_axis, y_axis, z_axis) {

  //Creates the axis_vector struct
  struct axis_vector rotation_matrix;

  //Gets the values for struct axis
  float rotation_x_x_axis = cos(y_axis) * cos(z_axis);
  float rotation_x_y_axis = (cos(z_axis) * sin(y_axis)) - (cos(x_axis) * sin(z_axis));
  float rotation_x_z_axis = (cos(z_axis) * sin(y_axis) * cos(x_axis)) + (sin(y_axis) * sin(z_axis));

  //Puts the values in the struct
  rotation_matrix.x_value, rotation_x_x_axis;
  rotation_matrix.y_value, rotation_x_y_axis;
  rotation_matrix.z_value, rotation_x_z_axis;

  //returns the struct
  return rotation_matrix;
}

//Generates Pitch and Roll
float gyroscope_pitch_roll_retrieval(rotation_matrix) {

  //Generates Roll and Pitch from the given Rotation
  float roll = atan((-1 * rotation_matrix.y_axis) / rotation_matrix.z_axis);
  float pitch = atan((-1 * rotation_matrix.x_axis) / sqrt((pow(rotation_matrix.x_axis, 2.0) + pow(rotation_matrix.z_axis, 2.0))));

  return roll, pitch;
}

float magnetometer_yaw(rotation_matrix, roll, pitch) {
    //Calculate yaw with roll and pitch
    float yaw = (sin(roll) * rotation_matrix.z_axis) - (cos(roll) * rotation_matrix.y_axis) / (cos(pitch) * rotation_matrix.x_axis) + (sin(roll) * sin(pitch) * rotation_matrix.y_axis) + (cos(roll) * sin(pitch) * rotation_matrix.z_axis);
    return yaw;
}

void predictions(pitch, time_change, bias, ) {

}

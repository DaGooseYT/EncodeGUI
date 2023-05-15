#include "args.hpp"

/// <summary>
/// Sets the profile for the encoder.
/// </summary>
/// <param name="profile">The encoder profile.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::videoProfile(QString profile) {
	return(QString("-profile:v %1").arg(profile));
}

/// <summary>
/// Sets the profile level for the encoder.
/// </summary>
/// <param name="level">The encoder profile level.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::videoProfileLevel(QString level) {
	return(QString("-level:v %1").arg(level));
}
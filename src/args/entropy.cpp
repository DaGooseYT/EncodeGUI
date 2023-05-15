#include "args.hpp"

/// <summary>
/// x264 entropy coder.
/// </summary>
/// <param name="coder">The coder (index) to use.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::entropyCoding(int coder) {
	return(QString("-coder %1").arg(coder));
}
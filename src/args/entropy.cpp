#include "../../include/args.hpp"

/// <summary>
/// x264 entropy coder.
/// </summary>
/// <param name="coder">The coder (index) to use.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::EntropyCoding(int coder) {
	return QString(" -coder %1").arg(coder);
}
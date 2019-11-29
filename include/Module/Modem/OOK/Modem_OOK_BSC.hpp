/*!
 * \file
 * \brief Class module::Modem_OOK_BSC.
 */
#ifndef MODEM_OOK_BSC_HPP_
#define MODEM_OOK_BSC_HPP_

#include "Module/Modem/OOK/Modem_OOK.hpp"

namespace aff3ct
{
namespace module
{
template <typename B = int, typename R = float, typename Q = R>
class Modem_OOK_BSC : public Modem_OOK<B,R,Q>
{
protected:
	Q log_pe_1_pe; // = log(pe / (1- pe))

public:
	Modem_OOK_BSC(const int N, const int n_frames = 1);
	virtual ~Modem_OOK_BSC() = default;

	virtual Modem_OOK_BSC<B,R,Q>* clone() const;

	void notify_noise_update();

protected:
	void check_noise();

	void _demodulate(const Q *Y_N1, Q *Y_N2, const int frame_id);
};
}
}

#endif /* MODEM_OOK_BSC_HPP_ */

#ifndef CALIBRATORGREYCODE
#define CALIBRATORGREYCODE

#include "Calibrator.h"

#include "Codec.h"

using namespace std;

class CalibratorGrayCode : public Calibrator
{
    Q_OBJECT
    public:
        CalibratorGrayCode(unsigned int _screenCols, unsigned int _screenRows);
        CalibrationData calibrate();
        ~CalibratorGrayCode(){delete encoder; delete decoder;}
    private:
        Encoder *encoder;
        Decoder *decoder;
};

#endif // CALIBRATORGREYCODE


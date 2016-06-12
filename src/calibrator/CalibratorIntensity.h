/*
 *  Author: Benjamin Langmann (b.langmann@gmx.de)
 *  Date: 2016
 */

#ifndef CALIBRATORINTENSITY
#define CALIBRATORINTENSITY

#include "Calibrator.h"

using namespace std;

static void normalize(cv::Mat &frame)
{
    double a =   2.63220735e+02,  b = 4.63119497e-02, c =  1.77958189e+02, d = -4.24081956e-01,   g=7.41190370e-01;
    for (int i = 0; i < frame.rows; ++i)
    {
        cv::Vec3b* ptr = frame.ptr<cv::Vec3b>(i);
        for (int j = 0; j < frame.cols; ++j)
        {
            cv::Vec3b& in = ptr[j];
            uint8_t out = (-1/b)*std::log((std::pow((a-d) / (in[0] - d), 1/g) - 1) / (std::pow(2, 1/g) - 1)) + c;
            in[0] = out;
            in[1] = out;
            in[2] = out;
        }
    }
}


class CalibratorIntensity : public Calibrator
{
    Q_OBJECT
    public:
        CalibratorIntensity(unsigned int _screenCols, unsigned int _screenRows) : Calibrator(_screenCols, _screenRows) {
            N = 256;
        }
        CalibrationData calibrate() { return CalibrationData(); }
        ~CalibratorIntensity() {}

        virtual cv::Mat getCalibrationPattern(unsigned int depth) {
            cv::Mat pattern(screenRows, screenCols, CV_8UC3, cv::Scalar(0,0,0));
            pattern/*(cv::Rect(256+128,256,256,256))*/.setTo(cv::Scalar(depth, depth, depth));
            return pattern;
        }
    private:
};

#endif // CALIBRATORINTENSITY


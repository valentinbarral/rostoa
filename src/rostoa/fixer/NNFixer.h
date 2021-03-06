/*
MIT License

Copyright (c) 2020 Group of Electronic Technology and Communications. University of A Coruna.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#ifndef GTEC_POZYX_NN_RANGING_FIXER_H
#define GTEC_POZYX_NN_RANGING_FIXER_H


#include <string>
#include <vector>
#include <stdint.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <armadillo>

#include "ros/ros.h"
#include <sstream>
#include <gtec_msgs/Ranging.h>

#include "rtwtypes.h"
#include "nnClassifier_types.h"


class NNFixer
{

public:
     NNFixer(ros::Publisher aPub, int mode, double minRange, double maxRange, double minRSS, double maxRSS);
    ~NNFixer();

    void newRanging(const gtec_msgs::Ranging::ConstPtr& ranging_msg);

private:
	double normalize(double value, double min, double max);
	double denormalize(double value, double min, double max);
    ros::Publisher ros_pub;
    int _mode;
    double _minRange, _maxRange, _minRSS, _maxRSS;
};


#endif

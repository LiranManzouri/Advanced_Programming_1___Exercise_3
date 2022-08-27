//
// Created by liran on 25/08/2022.
//

#ifndef ADVANCED_PROGRAMMING_1___EXERCISE_3_CLASSIFYCOMMAND_H
#define ADVANCED_PROGRAMMING_1___EXERCISE_3_CLASSIFYCOMMAND_H


#include "Command.h"

class ClassifyCommand : public Command {

public:
    ClassifyCommand(int *k, char classifiedTrainData[4096], char unclassifiedTestData[4096],
                    std::string *distanceMetric, std::vector<std::string> *flowerTypes, DefaultIO *dio) : Command(
            "classify data", k, classifiedTrainData, unclassifiedTestData, distanceMetric, flowerTypes, dio) {}

    void execute() override;
};


#endif //ADVANCED_PROGRAMMING_1___EXERCISE_3_CLASSIFYCOMMAND_H
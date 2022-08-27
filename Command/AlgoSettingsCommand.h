//
// Created by liran on 25/08/2022.
//

#ifndef ADVANCED_PROGRAMMING_1___EXERCISE_3_ALGOSETTINGSCOMMAND_H
#define ADVANCED_PROGRAMMING_1___EXERCISE_3_ALGOSETTINGSCOMMAND_H


#include "Command.h"

class AlgoSettingsCommand : public Command {

public:
    AlgoSettingsCommand(int *k, char classifiedTrainData[4096], char unclassifiedTestData[4096],
                        std::string *distanceMetric, std::vector<std::string> *flowerTypes, DefaultIO *dio)
                        : Command("algorithm settings", k, classifiedTrainData, unclassifiedTestData,
                                  distanceMetric, flowerTypes, dio) {}

    void execute() override;
};


#endif //ADVANCED_PROGRAMMING_1___EXERCISE_3_ALGOSETTINGSCOMMAND_H
#include <iostream>
#include <fstream>
#include <sstream>
#pragma warning (disable : 4996)

struct Weather {
	int day;
	int temperature;
	int wind;
	int humidity;
	int precipitation;
	char lightning[4];
	char clouds[9];
};

void readFromFile(Weather weather[], char* fileName) {

    std::ifstream file(fileName);

    if (!file.is_open())
    {
        std::cout << "Problem while opening the file" << std::endl;
        return;
    }

    std::string line;

    getline(file, line);
    int i = 0;

    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string token;

        getline(ss, token, ',');
        weather[i].day = stoi(token);

        getline(ss, token, ',');
        weather[i].temperature = stoi(token);

        getline(ss, token, ',');
        weather[i].wind = stoi(token);

        getline(ss, token, ',');
        weather[i].humidity = stoi(token);

        getline(ss, token, ',');
        weather[i].precipitation = stoi(token);

        getline(ss, token, ',');
        strncpy(weather[i].lightning, token.c_str(), 4);

        getline(ss, token, ',');
        strncpy(weather[i].clouds, token.c_str(), 9);

        i++;
    }
 
    file.close();
}

void printPerfectWeatherByIndex(Weather weather[], int i) {

    std::cout << "Most appropriate date is " << std::endl;
    std::cout << "Day: " << weather[i].day << std::endl;
    std::cout << "Temperature: " << weather[i].temperature << std::endl;
    std::cout << "Wind: " << weather[i].wind << std::endl;
    std::cout << "Humidity: " << weather[i].humidity << std::endl;
    std::cout << "Precipitation: " << weather[i].precipitation << std::endl;
    std::cout << "Lightning: " << weather[i].lightning << std::endl;
    std::cout << "Clouds:" << weather[i].clouds << std::endl;
}

int criteriaForRocketLaunch(Weather weather[]) {

    for (int i = 0; i < 15; i++) {
        
        if (weather[i].temperature >= 2 && weather[i].temperature <= 31) {
            if (weather[i].wind <= 10) {
                if (weather[i].humidity <= 60) {
                    if (weather[i].precipitation == 0) {
                        if (strcmp(weather[i].lightning, " No") == 0) {
                            if ((strcmp(weather[i].clouds, " Cumulus") != 0) && (strcmp(weather[i].clouds, " Nimbus") != 0 )) {
                                return i;
                            }
                        }
                    }
                }
            }
        }
    }
}

//------------------AVERAGE--------------------
int averageTemperature(Weather weather[]) {

    int sum = 0;
     
    for (int i = 0; i < 15; i++) {
        sum += weather[i].temperature;
    }

    return sum / 15;
}

int averageWind(Weather weather[]) {

    int sum = 0;

    for (int i = 0; i < 15; i++) {
        sum += weather[i].wind;
    }

    return sum / 15;
}

int averageHumidity(Weather weather[]) {

    int sum = 0;

    for (int i = 0; i < 15; i++) {
        sum += weather[i].humidity;
    }

    return sum / 15;
}

int averagePrecipitation(Weather weather[]) {

    int sum = 0;

    for (int i = 0; i < 15; i++) {
        sum += weather[i].precipitation;
    }

    return sum / 15;
}

const char* averageLightning(Weather weather[]) {

    int yes = 0;
    int no = 0;

    for (int i = 0; i < 15; i++) {
        if (strcmp(weather[i].lightning, " Yes") == 0) {
            yes++;
        }
        else {
            no++;
        }
    }

    float yesF = (float)yes / 15;
    float noF = (float)no / 15;

    if (yes > no) {
        return "Yes";
    }
    else if (no > yes) {
        return "No";
    }
    else {
        return "Are equel";
    }
}

const char* averageClouds(Weather weather[]) {

    int cumulus = 0;
    int stratus = 0;
    int nimbus = 0;
    int cirrus = 0;

    for (int i = 0; i < 15; i++) {
        if (strcmp(weather[i].clouds, "Cumulus") == 0) {
            cumulus++;
        }
        else if (strcmp(weather[i].clouds, "Stratus") == 0) {
            stratus++;
        }
        else if (strcmp(weather[i].clouds, "Nimbus") == 0) {
            nimbus++;
        }
        else if (strcmp(weather[i].clouds, "Cirrus") == 0) {
            cirrus++;
        }
    }
  
    float cumulusPercentage = (float)cumulus / 15;
    float stratusPercentage = (float)stratus / 15;
    float nimbusPercentage = (float)nimbus / 15;
    float cirrusPercentage = (float)cirrus / 15;

    if (cumulusPercentage >= stratusPercentage && cumulusPercentage >= nimbusPercentage && cumulusPercentage >= cirrusPercentage) {
        return "Cumulus";
    }
    else if (stratusPercentage >= cumulusPercentage && stratusPercentage >= nimbusPercentage && stratusPercentage >= cirrusPercentage) {
        return "Stratus";
    }
    else if (nimbusPercentage >= cumulusPercentage && nimbusPercentage >= stratusPercentage && nimbusPercentage >= cirrusPercentage) {
        return "Nimbus";
    }
    else {
        return "Cirrus";
    }
}

//------------------MAX----------------------

int maxTemperature(Weather weather[]) {

    int maxTemp = weather[0].temperature;

    for (int i = 1; i < 15; i++) {
        if (weather[i].temperature > maxTemp) {
            maxTemp = weather[i].temperature;
        }
    }

    return maxTemp;
}

int maxWind(Weather weather[]) {

    int maxWind = weather[0].wind;

    for (int i = 1; i < 15; i++) {
        if (weather[i].wind > maxWind) {
            maxWind = weather[i].wind;
        }
    }

    return maxWind;
}

int maxHumidity(Weather weather[]) {

    int maxHumidity = weather[0].humidity;

    for (int i = 1; i < 15; i++) {
        if (weather[i].humidity > maxHumidity) {
            maxHumidity = weather[i].humidity;
        }
    }

    return maxHumidity;
}

int maxPrecipitation(Weather weather[]) {
    
    int maxPrecipitation = weather[0].precipitation;

    for (int i = 1; i < 15; i++) {
        if (weather[i].precipitation > maxPrecipitation) {
            maxPrecipitation = weather[i].precipitation;
        }
    }

    return maxPrecipitation;
}

const char* maxLightning(Weather weather[]) {

    int yes = 0;
    int no = 0;

    for (int i = 0; i < 15; i++) {
        if (strcmp(weather[i].lightning, " Yes") == 0) {
            yes++;
        }
        else {
            no++;
        }
    }

    if (yes > no) {
        return "Yes";
    }
    else if (no > yes) {
        return "No";
    }
    else {
        return "Are equel";
    }
}

const char* maxClouds(Weather weather[]) {

    int cumulus = 0;
    int stratus = 0;
    int nimbus = 0;
    int cirrus = 0;

    for (int i = 0; i < 15; i++) {
        if (strcmp(weather[i].clouds, "Cumulus") == 0) {
            cumulus++;
        }
        else if (strcmp(weather[i].clouds, "Stratus") == 0) {
            stratus++;
        }
        else if (strcmp(weather[i].clouds, "Nimbus") == 0) {
            nimbus++;
        }
        else if (strcmp(weather[i].clouds, "Cirrus") == 0) {
            cirrus++;
        }
    }

    if (cumulus >= stratus && cumulus >= nimbus && cumulus >= cirrus) {
        return "Cumulus";
    }
    else if (stratus >= cumulus && stratus >= nimbus && stratus >= cirrus) {
        return "Stratus";
    }
    else if (nimbus >= cumulus && nimbus >= stratus && nimbus >= cirrus) {
        return "Nimbus";
    }
    else {
        return "Cirrus";
    }
}

//-------------------MIN--------------------

int minTemperature(Weather weather[]) {

    int minTemp = weather[0].temperature;

    for (int i = 1; i < 15; i++) {
        if (weather[i].temperature < minTemp) {
            minTemp = weather[i].temperature;
        }
    }

    return minTemp;
}

int minWind(Weather weather[]) {

    int minWind = weather[0].wind;

    for (int i = 1; i < 15; i++) {
        if (weather[i].wind < minWind) {
            minWind = weather[i].wind;
        }
    }

    return minWind;
}

int minHumidity(Weather weather[]) {

    int minHumidity = weather[0].humidity;

    for (int i = 1; i < 15; i++) {
        if (weather[i].humidity < minHumidity) {
            minHumidity = weather[i].humidity;
        }
    }

    return minHumidity;
}

int minPrecipitation(Weather weather[]) {

    int minPrecipitation = weather[0].precipitation;

    for (int i = 1; i < 15; i++) {
        if (weather[i].precipitation < minPrecipitation) {
            minPrecipitation = weather[i].precipitation;
        }
    }

    return minPrecipitation;
}

const char* minLightning(Weather weather[]) {

    int yes = 0;
    int no = 0;

    for (int i = 0; i < 15; i++) {
        if (strcmp(weather[i].lightning, " Yes") == 0) {
            yes++;
        }
        else {
            no++;
        }
    }

    if (yes < no) {
        return "Yes";
    }
    else if (no < yes) {
        return "No";
    }
    else {
        return "Are equel";
    }
}

const char* minClouds(Weather weather[]) {

    int cumulus = 0;
    int stratus = 0;
    int nimbus = 0;
    int cirrus = 0;

    for (int i = 0; i < 15; i++) {
        if (strcmp(weather[i].clouds, " Cumulus") == 0) {
            cumulus++;
        }
        else if (strcmp(weather[i].clouds, " Stratus") == 0) {
            stratus++;
        }
        else if (strcmp(weather[i].clouds, " Nimbus") == 0) {
            nimbus++;
        }
        else if (strcmp(weather[i].clouds, " Cirrus") == 0) {
            cirrus++;
        }
    }

    if (cumulus <= stratus && cumulus <= nimbus && cumulus <= cirrus) {
        return "Cumulus";
    }
    else if (stratus <= cumulus && stratus <= nimbus && stratus <= cirrus) {
        return "Stratus";
    }
    else if (nimbus <= cumulus && nimbus <= stratus && nimbus <= cirrus) {
        return "Nimbus";
    }
    else {
        return "Cirrus";
    }
}

void writeToFile(Weather weather[]) {

    std::ofstream file("WeatherReport.csv");

    if (!file.is_open())
    {
        std::cout << "Problem while opening the file" << std::endl;
        return;
    
    }
    file << "Type, Temperature (C), Wind (m/s), Humidity (%), Precipitation (%), Lightning, Clouds" << "\n";

    file << "Average" << ", " << averageTemperature(weather) << ", " << averageWind(weather) << ", " << averageHumidity(weather) << ", "
        << averagePrecipitation(weather) << ", " << averageLightning(weather) << ", " << averageClouds(weather) << "\n";

    file << "Max" << ", " << maxTemperature(weather) << ", " << maxWind(weather) << ", " << maxHumidity(weather) << ", "
        << maxPrecipitation(weather) << ", " << maxLightning(weather) << ", " << maxClouds(weather) << "\n";

    file << "Min" << ", " << minTemperature(weather) << ", " << minWind(weather) << ", " << minHumidity(weather) << ", "
        << minPrecipitation(weather) << ", " << minLightning(weather) << ", " << minClouds(weather) << "\n";

    file.close();
}

int main() {

    Weather weather[64];
    int number = 0;
    int index = -1;
    char fileName[20];
    char senderEmail[20];
    char password[20];
    char receiverEmail[20];
    
    std::cout << " Welcome to space menu " << "\n"
              << " Press 1 for English" << "\n"
              << " Press 2 for German" << "\n";

    std::cin >> number;

    switch (number)
    {
    case 1: {

        std::cout << "Enter file name: " << std::endl;
        std::cin >> fileName;

        std::cout << "Enter sender email address: " << std::endl;
        std::cin >> senderEmail;

        std::cout << "Enter password: " << std::endl;
        std::cin >> password;

        std::cout << "Enter receiver email address: " << std::endl;
        std::cin >> receiverEmail;

        std::cout << "\n";

        readFromFile(weather, fileName);
        index = criteriaForRocketLaunch(weather);
        writeToFile(weather);
        printPerfectWeatherByIndex(weather, index);

    } break;
    case 2: {

        std::cout << "Dateinamen eingeben: " << std::endl;
        std::cin >> fileName;

        std::cout << "E-Mail - Adresse des Absenders eingeben:  " << std::endl;
        std::cin >> senderEmail;

        std::cout << "Passwort eingeben: " << std::endl;
        std::cin >> password;

        std::cout << "Geben Sie die E-Mail - Adresse des Empfängers ein: " << std::endl;
        std::cin >> receiverEmail;

        std::cout << "\n";

        readFromFile(weather, fileName);
        index = criteriaForRocketLaunch(weather);
        writeToFile(weather);
        printPerfectWeatherByIndex(weather, index);

    } break;
    default: std::cout << "ERROR: Wrong menu format";
        break;
    }

    return 0;
}
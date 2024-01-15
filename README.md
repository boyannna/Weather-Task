# Weather-Task - Condition of task

The application should take 4 input parameters – File name (path to the file on the file system), Sender email address, Password, Receiver email address.

The type of the accepted input file for the weather forecast (filename parameter) is CSV and has the following structure (this is sample data; you can create your own and we mean to test it with more/different data):

The criteria for the weather conditions for a rocket launch is as follows:

* Temperature between 2 and 31 degrees Celsius;
* Wind speed no more than 10m/s (the lower the better);
* Humidity less than 60% (the lower the better);
* No precipitation;
* No lightings;
* No cumulus or nimbus clouds.

The application should calculate the most appropriate date for the space shuttle launch based on the above criteria and create new CSV file named “WeatherReport.csv” containing the same Parameter rows and for every Parameter aggregate the data for the given period as such:

* Average value
* Max value
* Min value
* Median value
* Most appropriate launch day parameter value

Make the application UI multilingual (English & German) with the ability to change the language.

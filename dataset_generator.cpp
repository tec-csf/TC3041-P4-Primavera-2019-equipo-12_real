#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()

using namespace std;

int main()
{
	ofstream file;
    file.open("dataset_antartida.txt");

    srand(time(0));  // Initialize random number generator.
    int num_base;
    float temperature;
    float level;
    float speed;

    int timeStamp_water_temp_base1 = 1439856000;
    int timeStamp_water_temp_base2 = 1439856000;
    int timeStamp_water_temp_base3 = 1439856000;

    int timeStamp_water_level_base1 = 1439856000;
    int timeStamp_water_level_base2 = 1439856000;
    int timeStamp_water_level_base3 = 1439856000;

    int timeStamp_air_temp_base1 = 1439856000;
    int timeStamp_air_temp_base2 = 1439856000;
    int timeStamp_air_temp_base3 = 1439856000;


    vector<string> tag_base_names;

    tag_base_names.push_back("D85_skiway_Coats_Land");
    tag_base_names.push_back("S17_Schirmacher_region");
    tag_base_names.push_back("Vostok_Atka_bay");

    if (file.fail())
    {
        cout << "No se pudo abrir el archivo "<< endl;
        exit(1);
    }
    
    else 
    {
    	file << "# DDL" << "\n\n";
    	file << "CREATE DATABASE ANTARTIC_research_database" << "\n\n";
    	file << "# DML" << "\n\n";
    	file << "# CONTEXT-DATABASE: ANTARTIC_research_database" << "\n\n";

    	#pragma omp parallel for
        for (int j = 0; j < 2222222; j++)
        {
        	temperature = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/80));
            file << "water_temp" << ",base=" << tag_base_names[0] << " temperature=-" << temperature << " " << timeStamp_water_temp_base1 <<"\n";
            timeStamp_water_temp_base1 += 360;
        }

        #pragma omp parallel for
        for (int j = 0; j < 2222222; j++)
        {
        	temperature = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/80));
            file << "water_temp" << ",base=" << tag_base_names[1] << " temperature=-" << temperature << " " << timeStamp_water_temp_base2 <<"\n";
            timeStamp_water_temp_base2 += 360;
        }

        #pragma omp parallel for
        for (int j = 0; j < 2222222; j++)
        {
        	temperature = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/80));
            file << "water_temp" << ",base=" << tag_base_names[2] << " temperature=-" << temperature << " " << timeStamp_water_temp_base3 <<"\n";
            timeStamp_water_temp_base3 += 360;
        }

        #pragma omp parallel for
     	for (int j = 0; j < 2222222; j++)
        {
        	level = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/15));
            file << "water_level" << ",base=" << tag_base_names[0] << " level=" << level << " " << timeStamp_water_level_base1 <<"\n";
            timeStamp_water_level_base1 += 360;
        }

        #pragma omp parallel for
        for (int j = 0; j < 2222222; j++)
        {
        	level = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/15));
            file << "water_level" << ",base=" << tag_base_names[1] << " level=" << level << " " << timeStamp_water_level_base2 <<"\n";
            timeStamp_water_level_base2 += 360;
        }

        #pragma omp parallel for
        for (int j = 0; j < 2222222; j++)
        {
        	level = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/15));
            file << "water_level" << ",base=" << tag_base_names[2] << " level=" << level << " " << timeStamp_water_level_base3 <<"\n";
            timeStamp_water_level_base3 += 360;
        }

        #pragma omp parallel for
        for (int j = 0; j < 2222222; j++)
        {
        	temperature = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/60));
            file << "air_temp" << ",base=" << tag_base_names[0] << " temperature=-" << temperature << " " << timeStamp_air_temp_base1 <<"\n";
            timeStamp_air_temp_base1 += 360;
        }

        #pragma omp parallel for
        for (int j = 0; j < 2222222; j++)
        {
        	temperature = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/60));
            file << "air_temp" << ",base=" << tag_base_names[1] << " temperature=-" << temperature << " " << timeStamp_air_temp_base2 <<"\n";
            timeStamp_air_temp_base2 += 360;
        }

        #pragma omp parallel for
        for (int j = 0; j < 2222222; j++)
        {
        	temperature = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/60));
            file << "air_temp" << ",base=" << tag_base_names[2] << " temperature=-" << temperature << " " << timeStamp_air_temp_base3 <<"\n";
            timeStamp_air_temp_base3 += 360;
        }
    }

    return 0;
}
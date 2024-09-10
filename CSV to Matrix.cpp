#include "iostream"
#include "fstream"
#include "sstream"
#include "string"
#include "Eigen/Dense"

Eigen :: MatrixXd csv_to_matrix(std :: string csv_path){
    
    std :: string reader;
    Eigen :: MatrixXd values(0,0);
    int x_count = 0;
    int y_count = 0;
    
    std :: ifstream file(csv_path);
    
    while(getline(file,reader)){
        
        std :: stringstream input(reader);
        std :: string dummy;
        int dummy_count = 0;
        
        
        while(getline(input,dummy,',')){
            
            if(x_count == 0){
                
                values.conservativeResize(x_count+1,y_count+1);
                values(x_count,y_count) = std :: stod(dummy);
                y_count += 1;
                
            }else{
                values.conservativeResize(x_count+1,y_count);
                values(x_count,dummy_count) = std :: stod(dummy);
                dummy_count+=1;
            }
            
        }
        
        x_count += 1;
        
    }
    
    return values;
    
}

int main(){
    
    std :: string path = "//Users//devvratchaubal//Documents//data.csv";
    std :: cout<<csv_to_matrix(path)<<std :: endl;
    
}

    #include<iostream>
    #include<vector>
    #include<map>

    using namespace std;

    //Creating a function which would return the output of the equation for a random value "val"

    double equation(map<double,double> parameters,double val){
        
        double output;
        
        for(auto&[coef,index] : parameters){
            
            output+= coef* pow(val,index);
            
        }
        
        return output;
    }


    //Creating a function which would return the derivative of the function for a random value "val"

    double derivative(map<double,double> parameters, double val){
        
        return (equation(parameters, val+0.0001) - equation(parameters, val))/0.0001;
        
    }


    //Applying the requirement to find the root of the equation
    double Newton_Raphson(map<double,double> parameters, double val){
        
        int length = parameters.size();
        double root = val;
        
        for(int i = 0; i<1000 ;i ++){
            
            root = root - equation(parameters , root) / derivative (parameters, root);
            
            if(fabs(equation(parameters,root))<0.0005){
                return root;
            }
            
        }
        
        return NULL;
    }

    int main(){
        
        map<double,double> attributes = {{2.5,3},{6,7},{5,0},{25,-3},{53,2}};
        
        double root = Newton_Raphson(attributes,2);
        
        cout<<root<<endl;
        
    }





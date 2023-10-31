 #include<bits/stdc++.h>
using namespace std;
//function to create sparse matrix
vector<vector<int>>create(vector<vector<int>>matrix){
    vector<vector<int>>sparse_matrix;
    vector<int>temp1;
    temp1.push_back(matrix.size());
    temp1.push_back(matrix[0].size());
    temp1.push_back(0);
    sparse_matrix.push_back(temp1);
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
             if(matrix[i][j]!=0){
                vector<int>temp;
                temp.push_back(i);
                temp.push_back(j);
                temp.push_back(matrix[i][j]);
                sparse_matrix.push_back(temp);
                sparse_matrix[0][2]++;
             }
        }
    }
    return sparse_matrix;
}
//function to add two sparse matrix
vector <vector<int>> add(vector<vector<int>>a,vector<vector<int>>b){
    //first element of sparse matrix is number of rows,columns and non zero elements
      if(a[0][0]!=b[0][0]||a[0][1]!=b[0][1]){
          cout<<"Invalid matrix";
          return {};
      };
        vector<vector<int>>c;
        vector<int>temp1;
        temp1.push_back(a[0][0]);
        temp1.push_back(a[0][1]);
        temp1.push_back(0);
        c.push_back(temp1);
        for(int i=0;i<a.size();i++){
                if(a[i][0]==b[i][0]&&a[i][1]==b[i][1]){
                    vector<int>temp;
                    temp.push_back(a[i][0]);
                    temp.push_back(a[i][1]);
                    temp.push_back(a[i][2]+b[i][2]);
                    c.push_back(temp);
                    c[0][2]+=1;
                }
                else {
                    c.push_back(a[i]);
                    c.push_back(b[i]);
                    c[0][2]+=2;
                }
        }
        sort(c.begin()+1,c.end());
        return c;
}
// Function to display the sparse matrix
void display(vector<vector<int>>sparse_matrix){
    for(int i=0;i<sparse_matrix.size();i++){
         for(int j=0;j<sparse_matrix[i].size();j++){
              cout<<sparse_matrix[i][j]<<" ";
         }
         cout<<endl;
    }
}
int main(){
    vector<vector<int>>matrix1={{1,0,0,0,0},{0,2,9,0,0},{0,0,3,0,0},{0,0,0,4,0},{0,0,0,0,5}};
    vector<vector<int>>matrix2={{1,0,0,3,0},{0,2,9,0,0},{0,0,3,0,100},{0,3,0,4,0},{24,0,0,0,5}};
    vector<vector<int>>sparse_matrix1=create(matrix1);
    vector<vector<int>>sparse_matrix2=create(matrix2);

vector<vector<int>>sparse_matrix3=add(sparse_matrix1,sparse_matrix2);
display(sparse_matrix3);
     return 0;
}
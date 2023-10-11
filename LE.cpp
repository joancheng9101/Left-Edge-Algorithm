#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Vertices {
public :
    int predecessor[100] ;
    int predecessor_num ;
    int lable;
    int resource_type;
    int left_edge;
    int right_edge;
};

void left_edge_insertion_sort(Vertices* vertices, int vertices_num){
    for(int i; i<vertices_num; i++){
        Vertices t = vertices[i];
        int j;
        for(j=i-1; j>=0 && t.left_edge < vertices[j].left_edge; j--){
            vertices[j+1] = vertices[j];
        }
        vertices[j+1] = t;
    }
}

void remove_arr(Vertices* vertices, int* d, int num){
    int index=0;
    for(int i = 0 ; i < num ; i++){
        if(!d[i]) vertices[index++] = vertices[i];
        d[i]=0;
    }
}

int main(int argc, char** argv){
    ifstream in;
    ofstream out;
    string input_file;
    string output_file;
    Vertices vertices[100];
    Vertices Rone[100];
    Vertices Rtwo[100];
    Vertices Rthree[100];
    Vertices Rfour[100];
    int index_one[100];
    int index_two[100];
    int index_three[100];
    int index_four[100];
    int vertices_num, resource_type_num, value, num_in_arr, can_select;
    int color[5] = {0,0,0,0,0}, resource_time[5] = {0,0,0,0,0}, need_delete[100]={0};
    int have_used[5] = {0,0,0,0,0}, resource_index[5] = {0,0,0,0,0};

    in.open(argv[1]);
    input_file = argv[1];
    output_file = input_file.replace(input_file.find("dfg"),3,"txt");
    out.open(output_file);

    in >> vertices_num >> resource_type_num;
    num_in_arr = vertices_num;
    for(int i=0; i < vertices_num ; i++){
        vertices[i].predecessor_num=0;
    }
    for(int i=0; i < vertices_num ; i++){
        vertices[i].lable = i;
        for(int j=0 ; j < vertices_num ; j++){
            in >> value;
            if(value){
                vertices[j].predecessor[vertices[j].predecessor_num] = i ;
                vertices[j].predecessor_num ++ ;
            } 
        }
    }
    for (int i=0 ; i < vertices_num ; i++){
            in >> vertices[i].resource_type;
            in >> vertices[i].left_edge;
            in >> vertices[i].right_edge;
    }
    for(int i=0 ;i< vertices_num; i++){
        for(int j =0; j<vertices[i].predecessor_num ;j++){
            vertices[i].predecessor[j] = vertices[vertices[i].predecessor[j]].right_edge;
        }
    }

    left_edge_insertion_sort(vertices,vertices_num);  //sorting left_edge

    while(num_in_arr > 0){
        for(int i=0 ; i<num_in_arr; i++){
            if(vertices[i].left_edge >= resource_time[vertices[i].resource_type]){
                can_select = 1;
                for(int j=0 ; j< vertices[i].predecessor_num ; j++){
                    if(vertices[i].predecessor[j] <= vertices[i].left_edge )  
                    {  
                        can_select = 1;
                    }
                    else {
                        can_select = 0;
                    }
                }
                if(can_select){
                    can_select = 0;
                    need_delete[i]=1;
                    vertices_num--;   
                    resource_time[vertices[i].resource_type]=vertices[i].right_edge;
                    have_used[vertices[i].resource_type] = 1;
                    switch (vertices[i].resource_type)
                    {
                    case 1:
                        Rone[resource_index[1]++]=vertices[i];
                        break;
                    case 2:
                        Rtwo[resource_index[2]++]=vertices[i];
                        break;
                    case 3:
                        Rthree[resource_index[3]++]=vertices[i];
                        break;
                    case 4:
                        Rfour[resource_index[4]++]=vertices[i];
                        break;
                    default:
                        break;
                    }
                }
            }
        }
        for(int k=0 ; k<5 ; k++){
            if(have_used[k]){
                 switch (k)
                    {
                    case 1:
                        index_one[color[1]]=resource_index[1];  //index points to next one
                        break;
                    case 2:
                        index_two[color[2]]=resource_index[2];
                        break;
                    case 3:
                        index_three[color[3]]=resource_index[3];
                        break;
                    case 4:
                        index_four[color[4]]=resource_index[4];
                        break;
                    default:
                        break;
                    }
                color[k] ++ ; // lable elements with color
                resource_time[k] = 0 ;
                have_used[k] = 0;
            }
        }
        remove_arr(vertices,need_delete,num_in_arr);  //delete vertices
        num_in_arr = vertices_num;
    }

    for(int i =1  ; i<=resource_type_num ; i++){
        out << "Demand of resource" << i << ": " << color[i] << endl;
        int print_index,w;
        print_index =0;
        switch (i)
        {
        case 1:
            for(int j = 0 ; j<color[1]; j++){
                for( w = print_index ; w < index_one[j]; w++){
                    out << Rone[w].lable << " ";
                }
                print_index = index_one[j];
                out << "\n";
            }
            break;
        case 2:
            for(int j = 0 ; j<color[2]; j++){
                for( w = print_index ; w < index_two[j]; w++){
                    out << Rtwo[w].lable << " ";
                }
                print_index = index_two[j];
                out << "\n";
            }
            break;
        case 3:
            for(int j = 0 ; j<color[3]; j++){
                for( w = print_index; w < index_three[j]; w++){
                    out << Rthree[w].lable << " ";
                }
                print_index = index_three[j];
                out << "\n";
            }
            break;
        case 4:
            for(int j = 0 ; j<color[4]; j++){
                for( w = print_index; w < index_four[j]; w++){
                    out << Rfour[w].lable << " ";
                }
                print_index = index_four[j];
                out << "\n";
            }
            break;
        default:
            break;
        }
    }
    in.close();
    out.close();
    return 0;
}
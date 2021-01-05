#include <iostream>

using namespace std;

//리스트 클래스
//노드르 연결 해체 중간 삽입하는 메소드와 자료편집 메소드
//자료를 추출하는 메소드


//
//노드에는 메모리 절약을 위해 데이터의 공간만 담는다. 메소드는 담지 않는다.


struct example_data//data 의 형태나 종류만 편집하면  node에 다른 종류의 데이터도 담을 수 있음
{
    void dump()
    {
        cout<<str<<endl;
        cout<<num<<endl;
    }
    string str = "초기값";
    long num = 777;
};

//동적할당으로 데이터의 종류를 바꾸면 좋을 듯

struct node 
{
    long serial_num;
    struct node* ptr_previous = NULL;
    struct node* ptr_next = NULL;
    struct example_data data;
};

class linked_list
{
    struct node* head_pointer = NULL;//시작점 주소    //private를 구현해야 함
    struct node* tail_pointer = NULL;//끝점 주소      //private를 구현해야 함
    long length;                                //private를 구현해야 함
    public:
    linked_list()//컨스트럭터, 초기화 하기  
    {
        // head_pointer = new struct node();
    }

    linked_list(struct node* address)//컨스트럭터, 초기화 하기  
    {
        head_pointer = address;
    }

    linked_list(long input_length)//컨스트럭터, 초기화 하기  
    {
        cout<<"생성자 호출 완료"<<endl;
        // head_pointer = new struct node();
            add(input_length);
        cout<<"생성자 동작 완료"<<endl;
    }

    void add(long number_of_elements)
    {
        long i = 0;
        while(i < number_of_elements)
        {
        cout<<"add 호출 완료"<<endl;
        struct node* temp_node = NULL;
        struct node* temp_node_previous = NULL;
        //make 2 temporary spaces
        temp_node_previous = tail_pointer;//get ptr of previous node(=last node). tail_pointer: had been initialized to NULL;
        cout<<"add 초기화 완료"<<endl;
        if(head_pointer == NULL)
        {
            head_pointer = new struct node();
            cout<<"add 분기1 완료"<<endl;
            temp_node = head_pointer;
        }
        else
        {
            temp_node = new struct node();
            cout<<"add 분기2 완료"<<endl;
            (*temp_node_previous).ptr_next = temp_node;
        }
        cout<<"add 노드할당 완료"<<endl;
        (*temp_node).ptr_previous = temp_node_previous;
        (*temp_node).ptr_next = NULL;
        (*temp_node).serial_num = length++;//management length
        cout<<"add 노드연결 및 순번매기기 완료"<<endl;
        //linking and set serial_num
        tail_pointer = temp_node;
        cout<<"add 꼬리노드 대입연산 완료"<<endl;

        i++;    
        }
    }

    // void add(string push_pop)
    // {
    //     if(push_pop == "PUSH")
    //     {

    //     }
    //     if(push_pop == "POP")
    //     {

    //     }
    // }

    // void add(long serial_num)
    // {
        
    // }

    void subtract()
    {
        struct node* temp_node = tail_pointer;
        struct node* temp_node_previous = (*temp_node).ptr_previous;

        (*temp_node_previous).ptr_next = NULL;
        tail_pointer = temp_node_previous;
        length--;//management length
        delete temp_node;
    }
    
     struct node* search(long serial_num)
    {
        struct node* temp_1 = head_pointer;
        struct node* temp_2 = tail_pointer;
        cout<<"head_pointer"<<head_pointer<<endl;
        cout<<"tail_pointer"<<tail_pointer<<endl;
        int i = 0;
        cout<<"search 초기화 완료"<<endl;
        if(serial_num<0 || serial_num >= length)
        {
            cout<<"invalid access : serial_number is out of range"<<endl;
            return NULL;
        }
        if(serial_num <= (length/2))
        {
            cout<<"search 분기1 시작"<<endl;
            while(i < serial_num)
            {
                temp_2 = (*temp_1).ptr_next; 
                temp_1 = temp_2;
                i++;
            }
            return temp_1;
        }
        if(serial_num > (length/2))
        {
            cout<<"search 분기2 시작"<<endl;
            i = length-1;
            while(i > serial_num)
            {
                temp_1 = (*temp_2).ptr_previous; 
                cout<<"search 분기2.1 시작"<<endl;
                temp_2 = temp_1;
                cout<<"search 분기2.2 시작"<<endl;
                i--;
            }
            return temp_2;
        }
        cout<<"search 분기3(나머지)"<<endl;
        return NULL;
    }

    // void get_ptr()
    // {
        
    // }// 이미 search 함수에서 포인터를 반환 하고 있음 


    void dump(long serial_num)
    {
        struct node* temp_1 = head_pointer;
        struct node* temp_2 = tail_pointer;

        if(serial_num<=0 || serial_num > length)
        {
            cout<<"invalid access : serial_number is out of range"<<endl;
            return;
        }
            int i = 0;
            while(i < serial_num)
            {
                (*temp_1).data.dump();
                temp_2 = (*temp_1).ptr_next; 
                temp_1 = temp_2;
                i++;
            }
            return;

    }

    // void dump(long serial_num_1, long serial_num_2)
    // {
    //     if(serial_num<=0 || serial_num > length)
    //     {
    //         cout<<"invalid access : serial_number is out of range"<<endl;
    //         return 0;
    //     }

    //     if(serial_num<=0 || serial_num > length)
    //     {
    //         cout<<"invalid access : serial_number is out of range"<<endl;
    //         return 0;
    //     }
    //     while(serial_num > 0)
    // }

    ~linked_list()
    {
        // cout<<"소멸자 호출 완료"<<endl;
        // while(head_pointer != NULL)
        // {
        //     struct node* temp_node = tail_pointer;
        //     struct node* temp_node_previous = (*temp_node).ptr_previous;

        //     (*temp_node_previous).ptr_next = NULL;
        //     tail_pointer = temp_node_previous;

        //     delete temp_node;
        // }

        struct node* temp_1 = head_pointer;
        struct node* temp_2 = tail_pointer;

   
            int i = 0;
            while(i < length-1)
            {
                temp_2 = (*temp_1).ptr_next; 
                temp_1 = temp_2;
                i++;
            }
            return;
        cout<<"소멸자 동작 완료"<<endl;
    }


};




int main()
{
    linked_list list_1(3);
    list_1.add(2);
    cout<<"생성완료"<<endl;
    linked_list list_2();
    cout<<"생성완료"<<endl;
    list_1.search(3);

    cout<<"일련번호 출력"<<endl;
    cout<<(*(list_1.search(1))).serial_num<<endl;
    // cout<<"검색완료"<<endl;
    list_1.dump(3);
    
    

    return 0;
}


//소멸자 애러 해결 필요
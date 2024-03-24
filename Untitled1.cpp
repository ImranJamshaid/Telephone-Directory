#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Contact
{
    public:
    string Name;
    long int PhoneNo;
    string City;
    long int CNIC;
    
    Contact *Prev;
    Contact *Next;
    
    Contact(string N,long int PN,string C,long int NIC)
    {
        Name=N;
        PhoneNo=PN;
        City=C;
        CNIC=NIC;
        Prev=NULL;
        Next=NULL;
    }
};

class TelephoneDirectory
{
    private:
    Contact *head;
    Contact *tail;
    
    public:
    TelephoneDirectory()
    {
        head=NULL;
        tail=NULL;
    }
    
    bool isDigit(string N)
    {
        bool hasDigit=false;
        for(int i=0;i<N.length();i++)
        {
            if(isdigit(N[i]))
            {
                hasDigit=true;
                return(hasDigit);
            }
        }
        return(hasDigit);
    }
    
    bool isValidPN(long int PN)
    {
        string StringNum=to_string(PN);
        int first=StringNum[0]-'0';
        int TotalDigits=StringNum.length();
        
        if(TotalDigits==10&&first!=0)
        {
            return (true);
        }
        else
        {
            return(false);
        }
    }
    
    bool isValidNIC(long int NIC)
    {
        string StringNum=to_string(NIC);
        int first=StringNum[0]-'0';
        int TotalDigits=StringNum.length();
        
        if(TotalDigits==13&&first!=0)
        {
            return (true);
        }
        else
        {
            return(false);
        }
    }

    void InitialContact()
    {
        Contact* newContact;
    
        newContact = new Contact("Imran Jamshaid", 3217161030, "Lahore", 3520177835883);
        head = newContact;
        tail = newContact;
    
        newContact = new Contact("Farhan Akhtar", 3217161031, "Multan", 3520177835884);
        newContact->Prev = tail;
        tail->Next = newContact;
        tail = newContact;
    
        newContact = new Contact("Usama Gillani", 3217161033, "Karachi", 3520177835885);
        newContact->Prev = tail;
        tail->Next = newContact;
        tail = newContact;
    
        newContact = new Contact("Abdullah Abasi", 3217161034, "Islamabad", 3520177835886);
        newContact->Prev = tail;
        tail->Next = newContact;
        tail = newContact;
    }

    void AddContact()
    {
        string N;
        long int PN;
        string C;
        long int NIC;
        
        cin.ignore();
        cout<<"Enter Name: ";
        getline(cin,N);
        while(true)
        {
            if(!isupper(N[0])||isDigit(N))
            {
                cout<<"Invalid Input Enter Again: ";
                getline(cin,N);
            }
            else
            {
                break;
            }
        }
        
        cout<<"Enter Phone No(+92): ";
        cin>>PN;
        
        while(true)
        {
            if(isValidPN(PN))
            {
                break;
            }
            else
            {
                cout<<"Again Enter Phone No(+92): ";
                cin>>PN;
            }
        }
        
        cin.ignore();
        cout<<"Enter City Name: ";
        getline(cin,C);
        
        while(true)
        {
            if(!isupper(C[0])||isDigit(C))
            {
                cout<<"Invalid Input Enter Again: ";
                getline(cin,C);
            }
            else
            {
                break;
            }
        }
        cout<<"Enter CNIC: ";
        cin>>NIC;
        while(true)
        {
            if(isValidNIC(NIC))
            {
                break;
            }
            else
            {
                cout<<"CNIC must be 13 Digits: ";
                cin>>NIC;
            }
        }
        cin.ignore();
        
        Contact *newContact=new Contact(N,PN,C,NIC);
        
        if(head==NULL)
        {
            head=newContact;
            tail=newContact;
            return;
        }
        newContact->Prev=tail;
        tail->Next=newContact;
        tail=newContact;
        cout<<N<<" added Successfully ?"<<endl;
    }
    
    void SearchContact()
    {
        long int PN;
        cout<<"Enter PhoneNo: ";
        cin>>PN;
    
        if(head==NULL)
        {
            cout << "Telephone Directory is Empty!" << endl;
            return;
        }
    
        Contact *ptr = head;
        bool found = false;
    
        while (ptr!=NULL)
        {
            if(ptr->PhoneNo==PN)
            {
                found=true;
                cout<<"Contact Found!"<<endl;
                cout<<"Name: "<<ptr->Name<<endl;
                cout<<"Phone # "<<ptr->PhoneNo<<endl;
                cout<<"City: "<<ptr->City<<endl;
                cout<<"CNIC: "<<ptr->CNIC<<endl;
                break;
            }
            ptr=ptr->Next;
        }
        
        if(!found)
        {
            cout<<"Contact Not Found!"<<endl;
        }
    }

    void DeleteContact()
    {
        long int PN;
        cout<<"Enter PhoneNo: ";
        cin>>PN;
        Contact *ptr=head;
        
        while(ptr!=NULL)
        {
            if(ptr->PhoneNo==PN)
            {
                break;
            }
            ptr=ptr->Next;
        }
        if(ptr==NULL)
        {
            cout<<"Contact Not Found!"<<endl;
            return;
        }
    
        string N=ptr->Name;
        
        if(head==NULL)
        {
            cout<<"Telephone Directory is Empty!"<<endl;
            return;
        }
        else if(head->PhoneNo==PN)
        {
            head=head->Next;
            delete(ptr);
            cout<<N<<" Deleted Successfully ?"<<endl;
            return;
        }
        Contact *Previous=head;
        Contact *Current=head;
        Contact *AfterCurr=NULL;
        
        while(Current->Next!=NULL)
        {
            if(Current->PhoneNo==PN)
            {
                break;
            }
            Previous=Current;
            Current=Current->Next;
        }
        AfterCurr=Current->Next;
        if(AfterCurr==NULL)
        {
            Previous->Next=NULL;
            tail=Previous;
            delete(Current);
        }
        else
        {
            Previous->Next=AfterCurr;
            AfterCurr->Prev=Previous;
            delete(Current);
        }
        cout<<N<<" Deleted Successfully ?"<<endl;
    }
    
    void UpdateContact()
    { 
        cin.ignore();
        while(true)
        {
            string Name;
            cout<<"Enter Name to Update: ";
            getline(cin,Name);
            
            Contact *ptr=head;
            while(ptr!=NULL)
            {
                if(ptr->Name==Name)
                {
                    break;
                }
                ptr=ptr->Next;
            }
            if(ptr==NULL)
            {
                cout<<"Contact Not Found!"<<endl;
                return;
            }
            
            char Choice;
            cout<<"1) Name 2) Phone Number 3) City "<<endl;
            cout<<"Enter Choice to Update: ";
            cin>>Choice;
            
            cin.ignore();
            
            switch(Choice)
            {
                case'1':
                {
                    string newName;
                    cout<<"Enter New Name: ";
                    getline(cin,newName);
                    while(true)
                    {
                        if(!isupper(newName[0])||isDigit(newName))
                        {
                            cout<<"Invalid Input Enter Again!";
                            getline(cin,newName);
                        }
                        else
                        {
                            break;
                        }
                    }
                    ptr->Name=newName;
                    break;
                }
                case'2':
                {
                    long int newPhoneNo;
                    cout<<"Enter New Phone Number: ";
                    cin>>newPhoneNo;
                    
                    while(true)
                    {
                        if(isValidPN(newPhoneNo))
                        {
                            break;
                        }
                        else
                        {
                            cout<<"Again Enter Phone No(+92): ";
                            cin>>newPhoneNo;
                        }
                    }
                    ptr->PhoneNo=newPhoneNo;
                    break;
                }
                case'3':
                {
                    string newCity;
                    cout<<"Enter New City Name: ";
                    getline(cin,newCity);
                    while(true)
                    {
                        if(!isupper(newCity[0])||isDigit(newCity))
                        {
                            cout<<"Invalid Input Enter Again: ";
                            getline(cin,newCity);
                        }
                        else
                        {
                            break;
                        }
                    }
                    
                    ptr->City=newCity;
                    break;
                }
                default:
                {
                    cout<<"Invalid Choice!"<<endl;
                }
            }
            cout<<"Do you want to make another update? (y/n): ";
            char again;
            cin>>again;
            if(again!='y')
            {
                break;
            }
            cout<<"Contact Added Successfully ?"<<endl;
            cin.ignore();
            
        }
    }
    
    void Sort()
    {
        if(head==NULL||head->Next==NULL)
        {
            return;
        }
        Contact *i, *j;
        string TempName;
        string TemNICity;
        long int TempPhoneNo;
        long int TemNICNIC;

        for(i=head;i->Next!=NULL;i=i->Next)
        {
            Contact *min=i;
            for(j=i->Next;j!=NULL;j=j->Next)
            {
                if(j->Name<min->Name)
                {
                    min=j;
                }
            }
            
            TempName=i->Name;
            i->Name=min->Name;
            min->Name=TempName;
            
            TemNICity=i->City;
            i->City=min->City;
            min->City=TemNICity;
            
            TempPhoneNo=i->PhoneNo;
            i->PhoneNo=min->PhoneNo;
            min->PhoneNo=TempPhoneNo;
            
            TemNICNIC=i->CNIC;
            i->CNIC=min->CNIC;
            min->CNIC=TemNICNIC;
        }
        cout<<"Sorted Successfully ?"<<endl;
    }

    void DisplayContact()
    {
        if(head==NULL)
        {
            cout<<"Telephone Directory is Empty!"<<endl;
            return;
        }
        cout<<endl;
        cout<<" \t\t\t "<<" Telephone Directory "<<endl;
        cout<<endl;
        Contact *ptr=head;
        
        const long int Second=20;
        cout<<setw(Second)<<left<<" Name"<<setw(Second)<<left<<"PhoneNo(+92)"<<setw(Second)<<left<<"CNIC"<<setw(Second)<<left<<"City"<<endl;
        cout<<setfill('-')<<setw(70)<<"-"<<setfill(' ')<<endl;
        while(ptr!=NULL)
        {
            cout<<setw(Second)<<left<<ptr->Name<<setw(Second)<<left<<ptr->PhoneNo<<setw(Second)<<left<<ptr->CNIC<<setw(Second)<<left<<ptr->City<<endl;
            ptr=ptr->Next;
        }
        cout<<setfill('-')<<setw(70)<<"-"<<setfill(' ')<<endl;
        /*cout << "\t\t\tTelephone Directory" << endl;
    cout << setw(20) << left << "Name" << setw(15) << left << "PhoneNo" << setw(20) << left << "City" << setw(15) << left << "CNIC" << endl;
    cout << setfill('-') << setw(70) << "-" << setfill(' ') << endl;

    Contact *ptr = head;
    while (ptr != NULL)
    {
        cout << setw(20) << left << ptr->Name << setw(15) << left << ptr->PhoneNo << setw(20) << left << ptr->City << setw(15) << left << ptr->CNIC << endl;
        ptr = ptr->Next;
    }*/
    }
};

int main()
{
    TelephoneDirectory T;
    T.InitialContact();
    
    while(true)
    {
        int Choice;
        
        cout<<"\nTelephone Directory"<<endl;
        cout<<"___________________"<<endl;
        cout<<"1) Add Contact "<<endl;
        cout<<"2) Modify Contact "<<endl;
        cout<<"3) Search Contact "<<endl;
        cout<<"4) Delete Contact "<<endl;
        cout<<"5) Sort Contact "<<endl;
        cout<<"6) Display Contact "<<endl;
        cout<<"7) Exit "<<endl;
        cout<<"___________________"<<endl;
        cin>>Choice;
    
    switch(Choice)
    {
        case 1:
        {
            T.AddContact();
            break;
        }
        case 2:
        {
            T.UpdateContact();
            break;
        }
        case 3:
        {
            T.SearchContact();
            break;
        }
        case 4:
        {
            T.DeleteContact();
            break;
        }
        case 5:
        {
            T.Sort();
            break;
        }
        case 6:
        {
            T.DisplayContact();
            break;
        }
        case 7:
        {
            return(0);
        }
        default:
        {
            cout<<"Invalid Choice!"<<endl;
            break;
        }
    }
}
}




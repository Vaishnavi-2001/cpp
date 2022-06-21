
#include <iostream>


using namespace std;



class pincodeexception:public exception
{
public:

    const char * what() const throw()
    {
        return "\n Sorry user we don't deliver to this pin code!!!!!!!!!\n PIN CODES where we deliver are \n 580021\n 580031 \n 1";
    }

};
class minorderexception:public exception
{
public:
    const char *what() const throw()
    {
        return "\n Sorry user you have to place an order of minimum 150 rupees!!!!!!!!!\n";
    }



};
class delivery_boy
{
    public:
    string b_name;
    string ph_no;
    string tracking_id;
    string v_no;

   void  get_delivery_boy()
    {


        b_name="kapil sharma";
        ph_no="8897602569";
        tracking_id="12KLOI";
        v_no="KA 1515 ";

    }

    void print_deliveryboy()
    {
        cout<<"\n\n\n";
        cout<<"########################################################################";
        cout<<"\n The details of the person who will be delivering you order is ";
        cout<<"\n Delivery boy name is ::"<<b_name;
        cout<<"\n "<< b_name<<" phone number is ::"<<ph_no;
        cout<<"\n To track your order use this Id on the application ------>"<<tracking_id;
        cout<<"\n The vehicle number plate Id is "<<v_no;
        cout<<"\n\n\n";



    }
delivery_boy(){}

};

class customer
{
public:
    string c_name;
    int c_phone;
    int pin_code;
    string no;
    string hname;
    string c;
    int static sum;


  void  getcustomer()
  {
      cout<<"\n Enter your name please ::: ";
      cin>>c_name;
      cout<<"\n Enter your phone number please ::: ";
      cin>>c_phone;
      cout<<"\n Dear user please enter your pin code :: ";
      cin>>pin_code;
  if(pin_code!=585102 && pin_code!=1 && pin_code!=580031  && pin_code!=580021)
  {

      pincodeexception z;
      throw z;
  }

  }

    void printcus()
    {
        cout<<"\n The details you entered are ";
        cout<<"\n  Your is  name:          "<<c_name;
        cout<<"\n  Your is  mobile number: "<<c_phone;
        cout<<"\n Your  pincode is        : "<<pin_code;


    }

   void get_address()
   {
       cout<<"\n Enter your flat/house no ";
       cin>>no;
       cout<<"\n Enter your house/appartment name ";
       cin>>hname;
       cout<<"\n Enter colony ";
       cin>>c;

   }
   void printadd()
   {
       cout<<"\n  Your flat/house no is: "<<no<<" house/appartment name is :"<<hname<<" Colony "<<c ;



   }
};

class bronze_cus:public customer
{
 public:
void sum_cb(int bill)
{
    float discount =0.005;
    bill=bill-(bill*discount);
    sum=bill;
    cout<<"\n HURRAY !! You are our bronze customer hence you availed a 5% discount ";
    cout<<"\n                                                                       Your current bill is = "<<bill;


}
};
class platinum_cus:public customer{
    public:

void sum_cp(int bill)
{
    float discount =0.03;
    bill=bill-(bill*discount);
    sum=bill;
    cout<<"\n HURRAY !!! You are our platinum customer hence you availed a 30% discount ";
     cout<<"\n                                                                         Your current bill is = "<<bill;


}
};
class premium_cus:public customer{
    public:

void sum_cpre(int bill)
{
    float discount =0.04;
    bill=bill-(bill*discount);
    sum=bill;
    cout<<"\n HURRAY!!!!!!!! You are our premium hence you availed a 40% discount ";
    cout<<"\n                                                                     Your current bill is = "<<bill;


}
};

class review{
public:
    int w;
    int rate;
    string comments;
    int get_review()

{
     cout<<"\n  Dear user do you want to comment on the restaurant";
     cout<<"\n Press 1 for yes \n press 0 for no ";
     cin>>w;
     if(w==1)
     {
         cout<<"\n Please enter your comments on this restaurant ";
         cout<<"\n User please type your comment without giving space ";
       cin>>comments;
     }

    cout<<"\n Please give your rating for this restaurant ";
    cin>>rate;
    cout<<"\n Thank you for rating our restaurant ";


  return rate;


}

};
class restaurant
{
    public:
        string r_name;
        int r_id;
        string phone;
        int n;
        int a[5];
        int j=1;
        int static bill;
        float r_rat;
        customer i;
        delivery_boy b;
        review z;


        restaurant(string r_name,int r_id,string phone,float r_rat)
        {
            this->r_name=r_name;
            this->r_id=r_id;
            this->phone=phone;
            this->r_rat=r_rat;


        }
        void print_res()
        {
            cout<<"\n Restaurant ID is :            "<<"["<<r_id<<"]";
            cout<<"\n Restaurant current rating is :"<<r_rat<<"*";
            cout<<"\n Restaurant name is  :         "<<r_name;
            cout<<"\n Restaurant phone number is :  "<<phone;



        }
        void get_customer()
        {

        i.getcustomer();
        }
        void print_customer()
        {
            i.printcus();
        }
        void getting_address()
        {
            i.get_address();

        }
        void printing_address()
        {
            i.printadd();
        }
        void delivery_details()
        {
            b.get_delivery_boy();
            b.print_deliveryboy();
        }

        void review()
       {
              int k;
        cout<<"\n The current rating of this restaurant is         : "<<r_rat;
         k=z.get_review();
     if(k==1 || k==2)
     {
           r_rat=r_rat-0.1;

     }
     if(k==3||k==4)
     {
         r_rat=r_rat+0.1;
     }
     if(k==5)
     {
         r_rat=r_rat+0.2;


     }
     cout<<"\n After your rating the rating has been changed to :           "<<r_rat;
 }

  void customer_sepration()
  {


      if(bill<500)
      {
          bronze_cus b;
          b.sum_cb(bill);

      }

      if(bill>500 && bill<1000)
      {
          platinum_cus p;
          p.sum_cp(bill);
      }
      if(bill>1000)
      {
          premium_cus e;
          e.sum_cpre(bill);
      }

  }

restaurant(){}



};

class indian_res:public restaurant
{
public:

    string r_name;
    string phone;
    int r_id;
    float r_rat;
    string menu[10];
    int price[10];
indian_res(string r_name,int r_id,string phone,float r_rat):restaurant(r_name,r_id,phone,r_rat)
    {

    }

    void fooditems()
    {

        menu[1]="South Indian Thali";
        menu[2]="North Indian Thali";
        price[1]=100;
        price[2]=150;

    }
 void   print_indian_restaurants()
 {

     restaurant::print_res();
     cout<<"\n The menu of this restaurant is \n";

     for(int i=1;i<3;i++)
     {
         cout<<"                                    "<<i<<")"<<" "<<menu[i]<<" "<<price[i]<<"\n";


     }

 }

 void billcal_i(int a[],int b[],int q)
 {

     for(int y=1;y<=q;y++)
    {

     bill=bill+b[y]*price[a[y]];

     }

       if(bill<150)
  {
      minorderexception m;
      throw m;

  }

  cout<<"\n\n\n";
  cout<<"\n Dear user is this your final order ";

  for(int y=1;y<=q;y++)
    {
        if(b[y]!=0)
    {
       cout<<"\n                                       ";
     cout<<menu[a[y]]<<"    Quantity    "<<b[y]<<"   Price  "<<price[a[y]];
     cout<<"\t";
     }
    }

     cout<<"\n          Your bill is = "<<bill;





 }

};

class multi_restaurant:public restaurant
{
public:

    string r_name;
    string phone;
    float  r_id;
    float r_rat;
    string menu1[10];
    int price1[10];

    multi_restaurant(string r_name,int r_id,string phone,float r_rat):restaurant(r_name,r_id,phone,r_rat)
    {

    }

    void fooditem()
    {

        menu1[1]="Pasta";
        menu1[2]="pizza";
        menu1[3]="Noodles";
        price1[1]=150;
        price1[2]=120;
        price1[3]=150;

    }
 void   print_multi_restaurants()
 {

     restaurant::print_res();
     cout<<"\n The menu of this restaurant is \n";
     for(int i=1;i<4;i++)
     {
         cout<<"                                    "<<i<<")"<<" "<<menu1[i]<<" "<<price1[i]<<"\n";


     }

 }
   void billcal_m(int a[],int b[],int q)
 {
     for(int y=1;y<=q;y++){

     bill=bill+b[y]*price1[a[y]];

     }
        if(bill<150)
  {
      minorderexception m;
      throw m;

  }


  cout<<"\n Dear user  this is your final order ";
  for(int y=1;y<=q;y++)
    {
        if(b[y]!=0){
       cout<<"\n                                  ";
      cout<<menu1[a[y]]<<"    "<<price1[a[y]]<<"   Quantity "<<b[y];

     }
    }

cout<<"\n\n";
  cout<<"\n Your bill in rupees = "<<bill;
 }
};

class payment
{
public:
    float disount;
    customer t;
};
class card:public payment
{
public:
    string card_no;
    float discount;

    void cal_dis()
    {
        cout<<"\n Enter your card no ";
        cin>>card_no;
        discount=0.01;
        t.sum=t.sum-(discount*t.sum);
        cout<<"\n ******************** Your discounted bill is : "<<t.sum<<" **************";


    }
};

class net_banking:public payment
{
public:
    string acc_no;
    float discount;

    void cal_dis()
    {
        cout<<"\n Enter your account number ";
        cin>>acc_no;
        discount=0.02;
        t.sum=t.sum-(discount*t.sum);
        cout<<"\n ******************** Your discounted bill is : "<<t.sum<<" **************";


    }
};

int restaurant::bill=0;
int customer::sum=0;

int main()
{  int p;
 p=1;
    while(p!=0)
{

    int z,p;

    int q,j,n,ch,a[50],b[50],h;
    j=1;
    q=0;
    int f;
    f=0;
  cout<<"\n WELCOME ";
    for(int y=0;y<50;y++)
    {
        a[y]=0;
        b[y]=0;
    }
  try{
    restaurant r;
    r.get_customer();
    r.print_customer();



    indian_res x1("JCP",01,"1222201234",4.0),x2("VENKATGIRI",02,"012344556",5.0);
    multi_restaurant m1("President",03,"1222201234",4.0),m2("Hans",04,"012344556",5.0);

    cout<<"\n\n\n User please enter you food choice ";
    cout<<"\n Press \n\n 1) for Indian restaurant Press \n 2) for Multi cuisine restaurant  ------> ";
    cin>>ch;

 switch(ch)
 {
     case 1 : {
            cout<<"**************************\n";
             cout<<"\n The restaurants available are";

            x1.fooditems();
            x2.fooditems();
            x1.print_indian_restaurants();
            cout<<"\n---------------------------------";
            x2.print_indian_restaurants();
            cout<<"\n---------------------------------";
            }

            break;


    case 2 :{
             cout<<"**************************\n";
             cout<<"\n The restaurants available are ";

            m1.fooditem();
            m2.fooditem();
            m1.print_multi_restaurants();
            cout<<"\n---------------------------------";
            m2.print_multi_restaurants();
            cout<<"\n---------------------------------";
                 }
            break;
              default:
              cout<<"\n Sorry no restaurant available for this input" ;
              break;

 }

    cout<<"\n Enter the restaurant ID from where u want to place the order ";
           cin>>n;

if(n>4 || n<1)
{
    cout<<"\n Sorry wrong restaurant id ";
}

if(n==1)
        {
               x1.print_indian_restaurants();


            while(j!=0)
            {

                cout<<"\n Pick the items you want to order ";

                cin>>f;
                if(f>2)
                {
                    cout<<"\n WRONG ITEM number ";

                }
                else

            {
                q++;
                a[q]=f;
                cout<<"     Enter quantity : ";
                cin>>b[q];
                }
                cout<<"\n Do you want to order another item ?: press '1' for YES '0' for NO ";
                cin>>j;


            }



    try{

            x1.billcal_i(a,b,q);
            cout<<"\n Are you sure u want to place this order \n press 1 for YES \n press 0 for NO : ";
            cin>>h;
            if(h==1)
        {
            r.customer_sepration();
            r.getting_address();
            cout<<"\n Dear user you want to pay using card or net banking \n choose 1 for card \n choose 2 for net banking ";
            cin>>z;
            if(z==1)
            {

                card c;
                c.cal_dis();


            }
            else{


                net_banking n;
                n.cal_dis();
            }
            x1.review();
            r.delivery_details();
            cout<<"\n Will be delivering to ";
            r.printing_address();
        }
        else
        {
              cout<<"\n Do you want to place your order again ? :\n press 1 for yes \n press 0 for no ";
               cin>>p;
        }
    }
          catch(exception& e)
            {
              cout<<e.what();
                             }



        }

if(n==2)
   {
                 x2.print_indian_restaurants();


            while(j!=0)
            {

               cout<<"\n Pick the items you want to order ";

                cin>>f;
                if(f>2)
                {
                    cout<<"\n WRONG ITEM number ";

                }
                else
                {
                    q++;
                    a[q]=f;
                    cout<<"     Enter quantity : ";
                    cin>>b[q];
                }
                cout<<"\n Do you want to order another item ?: press '1' for YES '0' for NO ";
                cin>>j;




            }
  try{

            x2.billcal_i(a,b,q);
            cout<<"\n Are you sure u want to place this order \n press 1 for YES \n press 0 for NO : ";
            cin>>h;
            if(h==1)
        {
            r.customer_sepration();
             r.getting_address();
            cout<<"\n Dear user you want to pay using card or net banking \n choose 1 for card \n choose 2 for net banking ";
            cin>>z;
            if(z==1)
            {

                card c;
                c.cal_dis();


            }
            else{


                net_banking n;
                n.cal_dis();
            }
            x2.review();
            r.delivery_details();
            cout<<"\n Will be delivering to ";
            r.printing_address();
  }
  else
  {
     cout<<"\n Do you want to place your order again ? :\n press 1 for yes \n press 0 for no ";
               cin>>p;
  }
  }
  catch(exception& e)
          {
              cout<<e.what();
          }

  }
 if(n==3)
         {
                  m1.print_multi_restaurants();


            while(j!=0)
            {

                cout<<"\n Pick the items you want to order ";
                 q++;
                cin>>f;
                if(f>3){
                cout<<"\n WRONG ITEM NUMBER ";

                }
                else{

                    q++;
                    a[q]=f;
                    cout<<"     Enter quantity : ";
                    cin>>b[q];
                }
                cout<<"\n Do you want to order another item ?: press '1' for YES '0' for NO ";
                cin>>j;


            }
 try{
            m1.billcal_m(a,b,q);
            cout<<"\n Are you sure u want to place this order \n press 1 for YES \n press 0 for NO : ";
            cin>>h;
            if(h==1)
        {
            r.customer_sepration();
             r.getting_address();
             cout<<"\n Dear user you want to pay using card or net banking \n choose 1 for card \n choose 2 for net banking ";
            cin>>z;
            if(z==1)
            {

                card c;
                c.cal_dis();


            }
            else{


                net_banking n;
                n.cal_dis();
            }
            m1.review();
             r.delivery_details();
             cout<<"\n Will be delivering to ";
            r.printing_address();
 }

            else
  {
      cout<<"\n Do you want to place your order again ? :\n press 1 for yes \n press 0 for no ";
               cin>>p;
  }
 }

             catch(exception& e)
          {
              cout<<e.what();
          }

  }
    if(n==4)
  {
    m2.print_multi_restaurants();


            while(j!=0)
            {

             cout<<"\n Pick the items number(s) want to order ";

                cin>>f;
                if(f>3)
            {
                cout<<"\n WRONG ITEM NUMBER ";

                }
                else{
                         q++;
                         a[q]=f;
                          cout<<"     Enter quantity : ";
                          cin>>b[q];

                }
                cout<<"\n Do you want to order another item ?: press '1' for YES '0' for NO ";
                cin>>j;


            }
  try{
            m2.billcal_m(a,b,q);
              cout<<"\n Are you sure u want to place this order \n press 1 for YES \n press 0 for NO : ";
            cin>>h;
            if(h==1)
        {
            r.customer_sepration();
             r.getting_address();
             cout<<"\n Dear user you want to pay using card or net banking \n choose 1 for card \n choose 2 for net banking ";
            cin>>z;
            if(z==1)
            {

                card c;
                c.cal_dis();


            }
            else{


                net_banking n;
                n.cal_dis();
            }
            m2.review();
        r.delivery_details();
        cout<<"\n Will be delivering to ";
            r.printing_address();

  }

          else
  {
      cout<<"\n Do you want to place your order again ? :\n press 1 for yes \n press 0 for no ";
               cin>>p;
  }
 }
  catch(exception& e)
          {
              cout<<e.what();
          }
  }





  }
   catch(exception& e)
          {
              cout<<e.what();
          }
         cout<<"\n Confirmation for quiting the application  or place another order \n if YES press 1 to place again \n if NO press 0 ";
          cin>>p;
          if(p==0)
          {
              break;
          }
}
    return 0;
}


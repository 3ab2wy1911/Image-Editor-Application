// FCI – Programming 1 – 2022 - Assignment 3
// Program Name: Filters_RGB.cpp
// Last Modification Date: 22/4/2022
// Yousef Ahmed : Filters : black & white , flip , mirror , detect edges
// Mohamed Ahmed : Filters : invert , enlarge , shuffle , rotate
// Yara Salah : Filters : merge , lighten & darken , shrink , blur
// Purpose: this program take a photo (RGB colored photo) and apply one of the 12 filters we have and save the new image

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <string>

#include "bmplib.cpp"
using namespace std;

unsigned char image[SIZE][SIZE][RGB];
unsigned char newimage[SIZE][SIZE][RGB];
unsigned char image2[SIZE][SIZE][RGB];
unsigned char orginal[SIZE][SIZE][RGB];

void loadImage_RGB();
void loadImage2_RGB();
void saveImage_RGB();
void saveImage_RGB2();
void shuffle_RGB();
void RotateImage90_RGB();
void RotateImage180_RGB();
void RotateImage270_RGB();
void enlarge_RGB();
void invert_RGB();
void black_and_wihte_RGB();
void filp_vertical_RGB();
void flip_horizontal_RGB();
void mirorr_lowerhalf_RGB();
void mirorr_upperhalf_RGB();
void mirorr_lefthalf_RGB();
void mirorr_righthalf_RGB();
void merge_RGB();
void darken_lighten_RGB();
void blur_RGB();
void shrink_RGB();
void saveImage_RGB_shrink ();

int main()
{
    int answer=1;
    while(answer!=0){
    cout << "Ahln ya user ya habibi "<< endl;
    cout << endl;
    cout << "1-Black and white filter " << endl;
    cout << "2-Filp filter " << endl;
    cout << "3-Mirorr filter "<< endl;
    cout << "4-Invert filter "<< endl;
    cout << "5-Enlarge filter "<< endl;
    cout << "6-Rotate filter "<< endl;
    cout << "7-Darken and lighten filter "<< endl;
    cout << "8-Shuffle filter "<< endl;
    cout << "9-Merge filter "<< endl;
    cout << "10-Blur filter "<< endl;
    cout << "11-shrink filter "<< endl;
    cout << "12-Edge dectet filter "<< endl;
    cout << "0-Exit "<< endl;
    cout << endl;

    cout << "choose the filter you want or 0 to exit "<< endl;
    cin >> answer;
    while (answer > 12 || answer < 0 )
    {
        cout << "Invalid input" << endl;
        cout << "You have to choose from 1 to 12 " << endl;
        cout << "Choose the filter you want "<< endl;
        cin >> answer;
    }

    if (answer == 1)
    {
         loadImage_RGB();
         black_and_wihte_RGB();
         saveImage_RGB();
    }
    else if (answer == 2)
    {
        string x;
        cout << "do you want to flip vertical or horizontal "<< endl;
        cin>> x;
        while (x !="horizontal" && x != "vertical" )
        {
            cout << "Invalid input " <<endl;
            cout << "You have to choose vertical or horizontal" << endl;
            cout << "Do you want to flip vertical or horizontal "<< endl;
            cin>> x;
        }
        if (x == "horizontal")
        {
            loadImage_RGB();
            flip_horizontal_RGB();
            saveImage_RGB ();
        }
        else if (x == "vertical")
        {
            loadImage_RGB();
            filp_vertical_RGB();
            saveImage_RGB ();
        }
    }
    else if (answer == 3)
    {
        string y;
        cout << "Do you want to mirror which side left or right or upper or lower "<< endl;
        cin>> y;
        while (y !="right" && y != "left" && y != "upper" && y != "lower")
        {
            cout << "Invalid input" << endl;
            cout << "Do you want to mirror which side left or right or upper or lower "<< endl;
            cin>> y;
        }
        if (y == "right")
        {
            loadImage_RGB();
            mirorr_righthalf_RGB();
            saveImage_RGB ();
        }
        else if (y == "left")
        {
            loadImage_RGB();
            mirorr_lefthalf_RGB();
            saveImage_RGB ();
        }
        else if (y == "upper")
        {
            loadImage_RGB();
            mirorr_upperhalf_RGB();
            saveImage_RGB();
        }
        else if (y == "lower")
        {
            loadImage_RGB();
            mirorr_lowerhalf_RGB();
            saveImage_RGB ();
        }
    }
    else if (answer == 4)
    {
        loadImage_RGB();
        invert_RGB();
        saveImage_RGB ();
    }
    else if (answer == 5)
    {
        loadImage_RGB();
        enlarge_RGB();
        saveImage_RGB2();

    }
    else if (answer == 6)
    {
        int ans;
        cout << "1 - Rotate by 90 degree\n"
        "2 - Rotate by 180 degree\n"
        "3 - Rotate by 270 degree\n";
        cin >> ans;
        while (ans > 3 || ans < 0)
        {
            cout << "Invalid input" << endl;
            cout << "1 - Rotate by 90 degree\n"
            "2 - Rotate by 180 degree\n"
            "3 - Rotate by 270 degree\n";
            cin >> ans;
        }
        if(ans == 1)
        {
            loadImage_RGB();
            RotateImage90_RGB();
            saveImage_RGB();
        }
        else if(ans == 2)
        {
            loadImage_RGB();
            RotateImage180_RGB();
            saveImage_RGB();
        }
        else if(ans == 3)
        {
            loadImage_RGB();
            RotateImage270_RGB();
            saveImage_RGB();
        }

    }
    else if (answer == 7)
    {
        loadImage_RGB();
        darken_lighten_RGB();
        saveImage_RGB();
    }
    else if (answer == 8)
    {
        loadImage_RGB();
        shuffle_RGB();
        saveImage_RGB2();
    }
    else if (answer == 9)
    {
        loadImage_RGB();
        loadImage2_RGB();
        merge_RGB();
        saveImage_RGB();
    }
    else if (answer == 10)
    {
        loadImage_RGB();
        blur_RGB();
        saveImage_RGB();
    }
    else if (answer == 11)
    {
        loadImage_RGB();
        shrink_RGB();
        saveImage_RGB_shrink ();
    }
    else if (answer == 0)
        cout << endl;
    }
}
//__________________________________
void saveImage_RGB_shrink () {
   char imageFileName[100];


   cout << "Enter the target image file name: ";
   cin >> imageFileName;


   strcat (imageFileName, ".bmp");
   writeRGBBMP(imageFileName, orginal);
}


//________________________________________
void loadImage_RGB () {
   char imageFileName[100];
   cout << "Enter the source image file name: ";
   cin >> imageFileName;
   strcat (imageFileName, ".bmp");
   readRGBBMP(imageFileName, image);
}
//______________________________________
void loadImage2_RGB()
{
    char imageFileName2[100];
    cout << "Enter the source image2 file name: ";
    cin >> imageFileName2;

    strcat (imageFileName2, ".bmp");
    readRGBBMP(imageFileName2, image2);
}

//_______________________________________
void saveImage_RGB () {
   char imageFileName[100];


   cout << "Enter the target image file name: ";
   cin >> imageFileName;


   strcat (imageFileName, ".bmp");
   writeRGBBMP(imageFileName, image);
}

//_________________________________________
void saveImage_RGB2 () {
   char imageFileName[100];


   cout << "Enter the target image file name: ";
   cin >> imageFileName;


   strcat (imageFileName, ".bmp");
   writeRGBBMP(imageFileName, newimage);
}
//_______________________________________
void shuffle_RGB()
{
    int p1,p2,p3,p4;
    cout<<"Please,Enter the number of the first quarter in the image: \n";
    cin>>p1;
    while(p1 < 1 || p1 > 4)
    {
        cout<<"Please,Enter a valid number of the first quarter in the image: \n";
        cin>>p1;
    }
    if(p1==1){
        for (int i=0; i<=SIZE/2; i++) {
            for (int j=0; j<=SIZE/2; j++) {
                    for(int k =0 ;k<3 ;k++){
                newimage[i][j][k] = image[i][j][k];
                }
            }
        }
    }
    else if (p1==2){
        for(int i=0 ; i<=SIZE/2 ; i++){
            for(int j =0; j<=SIZE/2 ; j++){
                      for(int k =0 ;k<3 ;k++){
                        newimage[i][j][k] = image[i][j+SIZE/2][k];
            }
            }
        }
    }
      else if (p1==3){
        for(int i=0 ; i<=SIZE/2;i++){
            for(int j =0; j<=SIZE/2 ; j++){
                      for(int k =0 ;k<3 ;k++){
                        newimage[i][j][k] = image[i+SIZE/2][j][k];
            }
            }
        }
    }
      else if (p1==4){
        for(int i=0 ; i<=SIZE/2;i++){
            for(int j =0; j<=SIZE/2 ; j++){
                      for(int k =0 ;k<3 ;k++){
                        newimage[i][j][k] = image[i+SIZE/2][j+SIZE/2][k];
            }
            }
        }
    }
    cout<<"Please,Enter the number of the second quarter in the image: \n";
    cin>>p2;
        while(p2<1||p2>4||p2==p1){
        if(p2<1||p2>4){
        cout<<"Please,Enter a valid number of the second quarter in the image: \n";
        cin>>p2;
        }
        if(p2==p1){
        cout<<"You already have entered the number of this quarter,Please enter number of another quarter to be put in the second quarter: \n";
        cin>>p2;
    }
    }

    if(p2==1){
        for (int i=0; i<=SIZE/2; i++) {
            for (int j=SIZE/2; j<=SIZE; j++) {
                      for(int k =0 ;k<3 ;k++){
                    newimage[i][j][k] = image[i][j-SIZE/2][k];
            }
            }
        }
    }
    if(p2==2){
        for (int i=0; i<=SIZE/2; i++) {
            for (int j=128; j<=SIZE; j++) {
                      for(int k =0 ;k<3 ;k++){
                    newimage[i][j][k] = image[i][j][k];
            }
            }
        }
    }
    else if (p2==3){
       for(int i=0 ; i<=SIZE/2;i++){
            for(int j =SIZE/2; j<=SIZE; j++){
                      for(int k =0 ;k<3 ;k++){
                        newimage[i][j][k] = image[i+SIZE/2][j-SIZE/2][k];
            }
            }
        }
    }
    else if (p2==4){
        for(int i=0 ; i<=SIZE/2;i++){
                for (int j =SIZE/2 ; j<=SIZE;j++){
                          for(int k =0 ;k<3 ;k++){
                        newimage[i][j][k] = image[i+SIZE/2][j][k];
                }
                }
            }
        }

    cout<<"Please,Enter the number of the third quarter in the image: \n";
    cin>>p3;
        while(p3<1||p3>4||p3==p1||p3==p2){
        if(p3<1||p3>4){
        cout<<"Please,Enter a valid number of the third quarter in the image: \n";
        cin>>p3;
        }
        if(p3==p1||p3==p2){
        cout<<"You already have entered the number of this quarter,Please enter number of another quarter to be put in the third quarter: \n";
        cin>>p3;
    }
    }

        if(p3==1){
            for (int i=SIZE/2; i<=SIZE; i++) {
                for (int j=0; j<=SIZE/2; j++) {
                          for(int k =0 ;k<3 ;k++){
                         newimage[i][j][k] = image[i-SIZE/2][j][k];
                    }
                }
            }
            }

    else if (p3==2){
        for (int i=SIZE/2; i<=SIZE; i++) {
            for (int j=0; j<=SIZE/2; j++) {
                      for(int k =0 ;k<3 ;k++){
                    newimage[i][j][k] = image[i-SIZE/2][j+SIZE/2][k];
                }
            }
        }
        }
    else if (p3==3){
       for(int i=SIZE/2 ; i<=SIZE;i++){
            for(int j =0; j<=SIZE/2; j++){
                      for(int k =0 ;k<3 ;k++){
                        newimage[i][j][k] = image[i][j][k];
            }
            }
        }
    }
    else if (p3==4){
        for(int i=SIZE/2 ; i<=SIZE;i++){
            for(int j =0; j<SIZE/2; j++){
                      for(int k =0 ;k<3 ;k++){
                        newimage[i][j][k] = image[i][j+SIZE/2][k];
            }
        }
        }
    }
     cout <<"Please,Enter the number of the fourth quarter in the image : \n";
     cin >>p4;
        while(p4<1||p4>4||p4==p1||p4==p2||p4==p3){
        if(p4<1||p4>4){
        cout<<"Please,Enter a valid number of the fourth quarter in the image : \n";
        cin>>p4;
        }
         if(p4==p1||p4==p2||p4==p3){
        cout<<"You already have entered the number of this quarter,Please enter number of another quarter to be put in the fourth quarter: \n";
        cin>>p4;
        }
    }


    if(p4==1){
            for (int i=SIZE/2; i<=SIZE; i++) {
                for (int j=SIZE/2; j<=SIZE; j++){
                          for(int k =0 ;k<3 ;k++){
                            newimage[i][j][k] =image[i-SIZE/2][j-SIZE/2][k];
                }
                }
            }
        }
    if(p4==2){
           for (int i=SIZE/2; i<=SIZE; i++) {
                for (int j=SIZE/2; j<=SIZE; j++) {
                          for(int k =0 ;k<3 ;k++){
                         newimage[i][j][k] =image[i-SIZE/2][j][k];
                }
                }
            }
        }
   if(p4==3){
           for (int i=SIZE/2; i<=SIZE; i++) {
                for (int j=SIZE/2; j<=SIZE; j++) {
                          for(int k =0 ;k<3 ;k++){
                         newimage[i][j][k] =image[i][j-SIZE/2][k];
                }
            }
           }
        }
    if(p4==4){
        for (int i=SIZE/2; i<=SIZE; i++) {
            for (int j=SIZE/2; j<=SIZE; j++) {
                      for(int k =0 ;k<3 ;k++){
                    newimage[i][j][k] = image[i][j][k];
            }
            }
        }
    }
}
//_____________________________________
void RotateImage90_RGB()
{
    for(int i=0; i<SIZE; i++)
    {
        for(int j=i; j<SIZE; j++)
        {
            for (int k =0 ; k<3 ;k++){
            int temp = image[i][j][k];
            image[i][j][k] = image[j][i][k];
            image[j][i] [k]= temp;
        }
        }
    }
    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<(SIZE/2); j++)
        {
         for (int k =0 ; k<3 ;k++){
            int temp = image[i][j][k];
            image[i][j][k] = image[i][SIZE-1-j][k];
            image[i][SIZE-1-j][k] = temp;
        }
    }
}
}
//___________________________________
void RotateImage180_RGB(){
    for(int i=0; i<2; i++){
    {
        RotateImage90_RGB();
    }
}
}
//____________________________
void RotateImage270_RGB()
{
    for(int i=0; i<3; i++)
    {
        RotateImage90_RGB();
    }
}

//____________________________
void enlarge_RGB (){
    int quarter ;
    cout<<"Please Enter the number of quarter : ";
    cin>>quarter;
    while(quarter <1 || quarter > 4){
        cout<<"Please Enter a valid number of the required quarter : ";
        cin>>quarter;
    }
    if(quarter == 1){
        for (int i=0 ;i<=SIZE/2;i++){
            for (int j=0 ;j<=SIZE/2;j++){
                    for(int k =0 ; k<=3 ; k++){
                newimage[i*2][j*2][k]=image[i][j][k];
                newimage[i*2][j*2+1][k]=image[i][j][k];
                newimage[i*2+1][j*2][k]=image[i][j][k];
                newimage[i*2+1][j*2+1][k]=image[i][j][k];
            }
            }
        }
    }
    else if(quarter == 2){
        for (int i=0 ;i<=SIZE/2;i++){
            for (int j=SIZE/2 ;j<=SIZE;j++){
                     for(int k =0 ; k<=3 ; k++){
                newimage[i*2][j*2][k]=image[i][j][k];
                newimage[i*2][j*2+1][k]=image[i][j][k];
                newimage[i*2+1][j*2][k]=image[i][j][k];
                newimage[i*2+1][j*2+1][k]=image[i][j][k];
            }
            }
        }
    }
    else if(quarter == 3){
        for (int i=0 ;i<SIZE/2;i++){
            for (int j=0 ;j<=SIZE/2;j++){
                     for(int k =0 ; k<=3 ; k++){
                newimage[i*2][j*2][k]=image[i+127][j][k];
                newimage[i*2][j*2+1][k]=image[i+127][j][k];
                newimage[i*2+1][j*2][k]=image[i+127][j][k];
                newimage[i*2+1][j*2+1][k]=image[i+127][j][k];
            }
            }
        }
    }
    else if(quarter == 4){
        for (int i=0 ;i<SIZE/2;i++){
            for (int j=SIZE/2 ;j<SIZE;j++){
                     for(int k =0 ; k<=3 ; k++){
                newimage[i*2][j*2][k]=image[i+127][j][k];
                newimage[i*2][j*2+1][k]=image[i+127][j][k];
                newimage[i*2+1][j*2][k]=image[i+127][j][k];
                newimage[i*2+1][j*2+1][k]=image[i+127][j][k];
            }
            }
        }
    }
}
//________________________________________________
void invert_RGB () {
    for (int i=0; i<SIZE; i++) {
      for (int j=0; j<SIZE; j++)
        for (int k=0; k<3; k++){
         image[i][j][k] = 255-image[i][j][k];
      }
   }
}
//_____________________________________________
void black_and_wihte_RGB()
{
    long avg = 0;
    for (int i =0 ; i < SIZE ; i++)
    {
        for (int j = 0 ; j < SIZE ; j++)
        {
            avg = image[i][j][0] +image[i][j][1] +image[i][j][2];
            avg /= RGB;
            if (avg > 127)
            {
                image[i][j][0] = 255;
                image[i][j][1] = 255;
                image[i][j][2] = 255;
            }
            else
            {
                image[i][j][0] = 0;
                image[i][j][1] = 0;
                image[i][j][2] = 0;
            }
        }
    }
}
//__________________________________________
void filp_vertical_RGB()
{
    for (int i =0 ; i < SIZE ; i++)
    {
        for (int j = 0 ; j < SIZE/2 ; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                swap( image[i][j][k] , image[i][SIZE-j][k]) ;
            }
        }
    }
}

//____________________________________________
void flip_horizontal_RGB()
{
    for (int i =0 ; i < SIZE/2 ; i++)
    {
        for (int j = 0 ; j < SIZE ; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                swap( image[i][j][k] ,  image[SIZE-i][j][k]) ;
            }
        }
    }
}

//_____________________________________________
void mirorr_lowerhalf_RGB()
{
     for (int i =0 ; i < SIZE/2 ; i++)
    {
        for (int j = 0 ; j < SIZE ; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                image[i][j][k] = image[SIZE-i][j][k];
            }
        }
    }
}

//______________________________________________
void mirorr_upperhalf_RGB()
{
     for (int i = SIZE ; i > SIZE/2 ; i--)
    {
        for (int j = 0 ; j < SIZE ; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                image[i][j][k] = image[SIZE-i][j][k];
            }
        }
    }
}

//_______________________________________________
void mirorr_lefthalf_RGB()
{
     for (int i = 0 ; i < SIZE ; i++)
    {
        for (int j = SIZE ; j > SIZE/2 ; j--)
        {
            for (int k = 0; k < 3; k++)
            {
                image[i][j][k] = image[i][SIZE-j][k];
            }
        }
    }
}

//_______________________________________________
void mirorr_righthalf_RGB()
{
     for (int i = 0 ; i < SIZE ; i++)
    {
        for (int j = 0 ; j < SIZE/2 ; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                image[i][j][k] = image[i][SIZE-j][k];
            }
        }
    }
}
//__________________________________________
void merge_RGB()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                image[i][j][k] = (image[i][j][k] + image2[i][j][k]) / 2;
            }
        }
    }
}
//_______________________________________________
void darken_lighten_RGB()
{
    int x;
    cout << "Enter 1 for darken and 2 for lighten: ";
    cin >> x;
    if (x == 1)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    if (image[i][j][k] > SIZE / 2)
                        image[i][j][k] -= SIZE / 2;
                    else
                         image[i][j][k] = 0;
                }
            }
        }
    }
    else if (x == 2)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    if (image[i][j][k] < SIZE / 2)
                        image[i][j][k] += SIZE / 2;
                    else
                        image[i][j][k] = 255;

                }
            }
        }
    }
}
//_________________________________________________
void blur_RGB()
{
    int x=0;
    for (int i = 0; i < SIZE; i++) {
        if (i == 0 || i == 255 || i == 1 || i == 254) {
            continue;
        }
        for (int j = 0; j < SIZE; j++) {
            if (j == 0|| j == 255|| j == 1 || j == 254) {
                continue;
            }
            for (int k = 0; k < 3; k++) {
                x = 0;
                for (int o = i - 2; o <= i + 2; o++) {
                    for (int y = j - 2; y <= j + 2; y++) {
                        x += image[o][y][k];
                    }
                }
                image[i][j][k] = (x) / 30;
            }
        }
    }
}
//________________________________________
void shrink_RGB()
{
    string shrink;
    int avg;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; ++k)
            {
                orginal[i][j][k] = 255;
            }
        }
    }
    cout << "Shrink to 1/2, 1/3 or 1/4: ";
    cin >> shrink;
    if (shrink == "1/2")
    {
        for (int i = 0, k = 0; i < SIZE; i += 2, k++)
        {
            for (int j = 0, o = 0; j < SIZE; j += 2, o++)
            {
                for (int l = 0; l < RGB; ++l)
                {
                    avg = (image[i][j][l] + image[i][j + 1][l] + image[i + 1][j][l] + image[i + 1][j + 1][l]) / 4;
                    orginal[k][o][l] = avg;
                }
            }
        }
    } else if (shrink == "1/3")
    {
        for (int i = 0, k = 0; i < SIZE; i += 3, k++)
        {
            for (int j = 0, o = 0; j < SIZE; j += 3, o++)
            {
                for (int l = 0; l < RGB; ++l)
                {
                    avg = (image[i][j][l] + image[i][j + 1][l] + image[i + 1][j][l] + image[i + 1][j + 1][l]) / 9;
                    orginal[k][o][l] = avg;
                }
            }
        }
    } else if (shrink == "1/4")
    {
        for (int i = 0, k = 0; i < SIZE; i += 4, k++)
        {
            for (int j = 0, o = 0; j < SIZE; j += 4, o++)
            {
                for (int l = 0; l < RGB; ++l)
                {
                    avg = (image[i][j][l] + image[i][j + 1][l] + image[i + 1][j][l] + image[i + 1][j + 1][l]) / 16;
                    orginal[k][o][l] = avg;
                }
            }
        }
    }else{
        cout<<"invalid shrink"<<endl;
    }
}

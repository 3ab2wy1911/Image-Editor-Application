// FCI – Programming 1 – 2022 - Assignment 3
// Program Name: Filters.cpp
// Last Modification Date: 22/4/2022
// Youssef Ahmed : filters : black & white , flip , mirror , detect edges
// Mohamed Ahmed : filters : invert , enlarge , shuffle , rotate
// Yara Salah : filters : merge , lighten & darken , shrink , blur
// Purpose: this program take a photo (gray scale photo) and apply one of the 12 filters we have and save the new image

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <string>

using namespace std;
#include "bmplib.cpp"

unsigned char image[SIZE][SIZE];
unsigned char newimage[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char orginal[SIZE][SIZE];


void loadImage();
void saveImage();
void savenew_Image();
void loadImage2();
void black_and_wihte();
void filp_vertical();
void flip_horizontal();
void mirorr_lowerhalf();
void mirorr_upperhalf();
void mirorr_lefthalf();
void mirorr_righthalf();
void enlarge();
void Invert();
void RotateImage90();
void RotateImage180();
void RotateImage270();
void Detect_Edges();
void Shuffle();
void merge();
void darken_lighten();
void blur();
void shrink();
void saveImage_shrink();


int main()
{
    int answer=1;
    while(answer!=0){
    cout << "Ahln ya user ya habibi "<< endl;
    cout << endl;
    cout << "1-Black and white filter " << endl;
    cout << "2-Flip filter " << endl;
    cout << "3-Mirror filter "<< endl;
    cout << "4-Invert filter "<< endl;
    cout << "5-Enlarge filter "<< endl;
    cout << "6-Rotate filter "<< endl;
    cout << "7-Detect edges filter "<< endl;
    cout << "8-Shuffle filter "<< endl;
    cout << "9-Merge filter "<< endl;
    cout << "10-darken and lighten filter "<< endl;
    cout << "11-Blur filter "<< endl;
    cout << "12-Shrink filter "<< endl;
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
         loadImage();
         black_and_wihte ();
         saveImage ();
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
            loadImage();
            flip_horizontal();
            saveImage ();
        }
        else if (x == "vertical")
        {
            loadImage();
            filp_vertical();
            saveImage ();
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
            loadImage();
            mirorr_righthalf();
            saveImage ();
        }
        else if (y == "left")
        {
            loadImage();
            mirorr_lefthalf();
            saveImage ();
        }
        else if (y == "upper")
        {
            loadImage();
            mirorr_upperhalf();
            saveImage ();
        }
        else if (y == "lower")
        {
            loadImage();
            mirorr_lowerhalf();
            saveImage ();
        }
    }
    else if (answer == 4)
    {
        loadImage();
        Invert();
        saveImage ();
    }
    else if (answer == 5)
    {
        loadImage();
        enlarge();
        savenew_Image();

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
            loadImage();
            RotateImage90();
            saveImage();
        }
        else if(ans == 2)
        {
            loadImage();
            RotateImage180();
            saveImage();
        }
        else if(ans == 3)
        {
            loadImage();
            RotateImage270();
            saveImage();
        }

    }
    else if (answer == 7)
    {
        loadImage();
        Detect_Edges();
        saveImage();
    }
    else if (answer == 8)
    {
        loadImage();
        Shuffle();
        savenew_Image();
    }
    else if (answer == 9)
    {
        loadImage();
        loadImage2();
        merge();
        saveImage();
    }
    else if (answer == 10)
    {
        loadImage();
        darken_lighten();
        saveImage();
    }
    else if (answer == 11)
    {
        loadImage();
        blur();
        saveImage();
    }
    else if (answer == 12)
    {
        loadImage();
        shrink();
        saveImage_shrink();
    }
    else if (answer == 0)
        cout << endl;
    }
}

//___________________________________________
void loadImage ()
{
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image);
}

//___________________________________________
void loadImage2 ()
{
    char imageFileName2[100];
    cout << "Enter the source image2 file name: ";
    cin >> imageFileName2;

    strcat (imageFileName2, ".bmp");
    readGSBMP(imageFileName2, image2);
}

//___________________________________________
void saveImage ()
{
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image);
}

//__________________________________________
void savenew_Image ()
{
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, newimage);
}
//__________________________________________
void saveImage_shrink() {
    char imageFileName[100];
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    strcat(imageFileName, ".bmp");
    writeGSBMP(imageFileName, orginal);
}
//____________________________________________
void black_and_wihte ()
{
    long avg = 0;
    for (int i =0 ; i < SIZE ; i++)
    {
        for (int j = 0 ; j < SIZE ; j++)
        {
            avg += image[i][j];
        }
    }
    avg /= (SIZE * SIZE);
    for (int i =0 ; i < SIZE ; i++)
    {
        for (int j = 0 ; j < SIZE ; j++)
        {
            if (image[i][j] > avg)
                image[i][j] = 255;
            else
                image[i][j] = 0;
        }
    }
}

//____________________________________________
void filp_vertical()
{
    for (int i =0 ; i < SIZE ; i++)
    {
        for (int j = 0 ; j < SIZE/2 ; j++)
        {
           swap( image[i][j] ,  image[i][SIZE-j]) ;
        }
    }
}

//____________________________________________
void flip_horizontal()
{
    for (int i =0 ; i < SIZE/2 ; i++)
    {
        for (int j = 0 ; j < SIZE ; j++)
        {
           swap( image[i][j] ,  image[SIZE-i][j]) ;
        }
    }
}

//_____________________________________________
void mirorr_lowerhalf()
{
     for (int i =0 ; i < SIZE/2 ; i++)
    {
        for (int j = 0 ; j < SIZE ; j++)
        {
            image[i][j] = image[SIZE-i][j];
        }
    }
}

//______________________________________________
void mirorr_upperhalf()
{
     for (int i = SIZE ; i > SIZE/2 ; i--)
    {
        for (int j = 0 ; j < SIZE ; j++)
        {
            image[i][j] = image[SIZE-i][j];
        }
    }
}

//_______________________________________________
void mirorr_lefthalf()
{
     for (int i = 0 ; i < SIZE ; i++)
    {
        for (int j = SIZE ; j > SIZE/2 ; j--)
        {
            image[i][j] = image[i][SIZE-j];
        }
    }
}

//_______________________________________________
void mirorr_righthalf()
{
     for (int i = 0 ; i < SIZE ; i++)
    {
        for (int j = 0 ; j < SIZE/2 ; j++)
        {
            image[i][j] = image[i][SIZE-j];
        }
    }
}

//_____________________________________________
void Detect_Edges()
{
    int avg = 0;
    unsigned char image2[SIZE][SIZE];

    for (int i = 0 ; i < SIZE ; i++)
    {
        for (int j = 0 ; j < SIZE ; j++)
        {
            image2[i][j] = 255;
            avg += image[i][j];
        }
    }
    avg /= (SIZE * SIZE);
    avg /= 3;

    for (int i = 0 ; i < SIZE ; i++)
    {
        for (int j = 0 ; j < SIZE ; j++)
        {
            if (image[i][j] - image[i-1][j-1] > avg || image[i][j] - image[i-1][j] > avg || image[i][j] - image[i+1][j] > avg || image[i][j] - image[i+1][j-1] > avg)
            {
                image2[i][j] = 0;

            }
            else if (image[i][j] - image[i][j+1] > avg || image[i][j] - image[i][j-1] > avg || image[i][j] - image[i+1][j+1] > avg || image[i][j] - image[i-1][j+1] > avg)
            {
                image2[i][j] = 0;
            }
        }
    }

    for (int i = 0 ; i < SIZE ; i++)
    {
        for (int j = 0 ; j < SIZE ; j++)
        {
           image[i][j] = image2[i][j];
        }
    }
}

//_____________________________________________
void Invert()
{
    for (int i=0; i<SIZE; i++)
    {
      for (int j=0; j<SIZE; j++)
       {
         image[i][j] = 255-image[i][j];
       }
   }
}

//____________________________________________
void enlarge()
{
    int quarter ;
    cout<<"Please Enter the number of quarter from 1 to 4 : ";
    cin>>quarter;
    while (quarter > 4 || quarter <0)
    {
        cout << "Invaild input " << endl;
        cout<<"Please Enter the number of quarter from 1 to 4 : ";
        cin>>quarter;
    }
    if(quarter == 1){
        for (int i=0 ;i<=SIZE/2;i++){
            for (int j=0 ;j<=SIZE/2;j++){
                newimage[i*2][j*2]=image[i][j];
                newimage[i*2][j*2+1]=image[i][j];
                newimage[i*2+1][j*2]=image[i][j];
                newimage[i*2+1][j*2+1]=image[i][j];
            }
        }
    }
    else if(quarter == 2){
        for (int i=0 ;i<=SIZE/2;i++){
            for (int j=SIZE/2 ;j<=SIZE;j++){
                newimage[i*2][j*2]=image[i][j];
                newimage[i*2][j*2+1]=image[i][j];
                newimage[i*2+1][j*2]=image[i][j];
                newimage[i*2+1][j*2+1]=image[i][j];
            }
        }
    }
    else if(quarter == 3){
        for (int i=0 ;i<SIZE/2;i++){
            for (int j=0 ;j<=SIZE/2;j++){
                newimage[i*2][j*2]=image[i+127][j];
                newimage[i*2][j*2+1]=image[i+127][j];
                newimage[i*2+1][j*2]=image[i+127][j];
                newimage[i*2+1][j*2+1]=image[i+127][j];
            }
        }
    }
    else if(quarter == 4){
        for (int i=0 ;i<SIZE/2;i++){
            for (int j=SIZE/2 ;j<SIZE;j++){
                newimage[i*2][j*2]=image[i+127][j];
                newimage[i*2][j*2+1]=image[i+127][j];
                newimage[i*2+1][j*2]=image[i+127][j];
                newimage[i*2+1][j*2+1]=image[i+127][j];
            }
        }
    }
}

//______________________________________________
void RotateImage270()
{
    for(int i=0; i<SIZE; i++)
    {
        for(int j=i; j<SIZE; j++)
        {
            int temp = image[i][j];
            image[i][j] = image[j][i];
            image[j][i] = temp;
        }
    }
    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<(SIZE/2); j++)
        {
            int temp = image[i][j];
            image[i][j] = image[i][SIZE-1-j];
            image[i][SIZE-1-j] = temp;
        }
    }
}

//________________________________________
void RotateImage180()
{
    for(int i=0; i<2; i++)
    {
        RotateImage270();
    }
}

//__________________________________________
void RotateImage90()
{
    for(int i=0; i<3; i++)
    {
        RotateImage270();
    }
}

//_______________________________________
void Shuffle()
{
    int p1,p2,p3,p4;
    cout<<"Please Enter the number of the first quarter in the image : ";
    cin>>p1;
    while (p1 > 4 || p1 < 0)
    {
        cout << "Invaild input " << endl;
        cout<<"Please Enter the number of the first quarter in the image : ";
        cin>>p1;
    }
    if(p1==1){
        for (int i=0; i<=SIZE/2; i++) {
            for (int j=0; j<=SIZE/2; j++) {
                newimage[i][j] = image[i][j];
            }
        }
    }
    else if (p1==2){
        for(int i=0 ; i<=SIZE/2 ; i++){
            for(int j =0; j<=SIZE/2 ; j++){
                        newimage[i][j] = image[i][j+SIZE/2];
            }
        }
    }
      else if (p1==3){
        for(int i=0 ; i<=SIZE/2;i++){
            for(int j =0; j<=SIZE/2 ; j++){
                        newimage[i][j] = image[i+SIZE/2][j];
            }
        }
    }
      else if (p1==4){
        for(int i=0 ; i<=SIZE/2;i++){
            for(int j =0; j<=SIZE/2 ; j++){
                        newimage[i][j] = image[i+SIZE/2][j+SIZE/2];
            }
        }
    }
    cout<<"Please Enter the number of the second quarter in the image : ";
    cin>>p2;
    while (p2 > 4 || p2 < 0 )
    {
        cout << "Invaild input " << endl;
        cout<<"Please Enter the number of the second quarter in the image : ";
        cin>>p2;
    }
    if(p2==1){
        for (int i=0; i<=SIZE/2; i++) {
            for (int j=SIZE/2; j<=SIZE; j++) {
                    newimage[i][j] = image[i][j-SIZE/2];
            }
        }
    }
    if(p2==2){
        for (int i=0; i<=SIZE/2; i++) {
            for (int j=128; j<=SIZE; j++) {
                    newimage[i][j] = image[i][j];
            }
        }
    }
    else if (p2==3){
       for(int i=0 ; i<=SIZE/2;i++){
            for(int j =SIZE/2; j<=SIZE; j++){
                        newimage[i][j] = image[i+SIZE/2][j-SIZE/2];
            }
        }
    }
    else if (p2==4){
        for(int i=0 ; i<=SIZE/2;i++){
                for (int j =SIZE/2 ; j<=SIZE;j++){
                        newimage[i][j] = image[i+SIZE/2][j];
                }
            }
        }

    cout<<"Please Enter the number of the third quarter in the image : ";
    cin>>p3;
    while (p3 > 4 || p3 < 0 )
    {
        cout << "Invaild input " << endl;
        cout<<"Please Enter the number of the third quarter in the image : ";
        cin>>p3;
    }
    if(p3==1){
        for (int i=SIZE/2; i<=SIZE; i++) {
            for (int j=0; j<=SIZE/2; j++) {
                        newimage[i][j] = image[i-SIZE/2][j];
                }
            }
        }

    else if (p3==2){
        for (int i=SIZE/2; i<=SIZE; i++) {
            for (int j=0; j<=SIZE/2; j++) {
                    newimage[i][j] = image[i-SIZE/2][j+SIZE/2];
                }
            }
        }
    else if (p3==3){
       for(int i=SIZE/2 ; i<=SIZE;i++){
            for(int j =0; j<=SIZE/2; j++){
                    newimage[i][j] = image[i][j];
            }
        }
    }
    else if (p3==4){
        for(int i=SIZE/2 ; i<=SIZE;i++){
            for(int j =0; j<SIZE/2; j++){
                    newimage[i][j] = image[i][j+SIZE/2];
            }
        }
    }
    cout <<"Please Enter the number of the fourth quarter in the image : ";
    cin >>p4;
    while (p4 > 4 || p4 < 0)
    {
        cout << "Invaild input " << endl;
        cout<<"Please Enter the number of the fourth quarter in the image : ";
        cin>>p4;
    }
    if(p4==1){
            for (int i=SIZE/2; i<=SIZE; i++) {
                for (int j=SIZE/2; j<=SIZE; j++){
                        newimage[i][j] =image[i-SIZE/2][j-SIZE/2];
                }
            }
        }
    if(p4==2){
           for (int i=SIZE/2; i<=SIZE; i++) {
                for (int j=SIZE/2; j<=SIZE; j++) {
                         newimage[i][j] =image[i-SIZE/2][j];
                }
            }
        }
   if(p4==3){
           for (int i=SIZE/2; i<=SIZE; i++) {
                for (int j=SIZE/2; j<=SIZE; j++) {
                         newimage[i][j] =image[i][j-SIZE/2];
                }
            }
        }
    if(p4==4){
        for (int i=SIZE/2; i<=SIZE; i++) {
            for (int j=SIZE/2; j<=SIZE; j++) {
                    newimage[i][j] = image[i][j];
            }
        }
    }
}

//____________________________________________________
void merge()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image[i][j] = (image[i][j] + image2[i][j]) / 2;
        }
    }
}

//__________________________________________
void darken_lighten()
{
    int x;
    cout << "Enter 1 for darken and 2 for lighten: ";
    cin >> x;
    if (x == 1) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {

                if (image[i][j] > SIZE / 2) {
                    image[i][j] -= SIZE / 2;
                } else
                    image[i][j] = 0;
            }
        }
    } else if (x == 2) {

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {

                if (image[i][j] < SIZE / 2) {
                    image[i][j] += SIZE / 2;
                }
                else
                    image[i][j] = 255;
            }
        }
    }
}
//_____________________________________________
void blur()
{
    int x;
    for (int i = 0; i < SIZE; i++)
    {
        if(i==0i==255i==1||i==254){
            continue;
        }
        for (int j = 0; j < SIZE; j++) {
            if(j==0j==255j==1||j==254){
                continue;
            }

                x=0;
                for (int o = i-2; o <= i+2; o++){
                    for (int y = j-2; y <=j+2; y++ ){
                        x+=image[o][y];
                    }
                }
                image[i][j]=(x)/25;
        }
    }
}
//__________________________________________
void shrink() {
    string shrink;
    int avg = 0;


    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            orginal[i][j] = 255;
        }
    }
    cout << "Shrink to 1/2, 1/3 or 1/4: ";
    cin >> shrink;
    if (shrink == "1/2") {
        for (int i = 0, k = 0; i < SIZE; i += 2, k++) {
            for (int j = 0, o = 0; j < SIZE; j += 2, o++) {
                avg = (image[i][j] + image[i][j + 1] + image[i + 1][j] + image[i + 1][j + 1]) / 4;
                orginal[k][o] = avg;
            }
        }
    } else if (shrink == "1/3") {
        for (int i = 0, k = 0; i < SIZE; i += 3, k++) {
            for (int j = 0, o = 0; j < SIZE ; j += 3, o++) {
                avg = (image[i][j] + image[i][j + 1] + image[i + 1][j] + image[i + 1][j + 1]) / 9;
                orginal[k][o] = avg;
            }
        }
    } else if (shrink == "1/4") {
        for (int i = 0, k = 0; i < SIZE; i += 4, k++) {
            for (int j = 0, o = 0; j < SIZE; j += 4, o++) {
                avg = (image[i][j] + image[i][j + 1] + image[i + 1][j] + image[i + 1][j + 1]) / 16;
                orginal[k][o] = avg;
            }
        }
    }

}

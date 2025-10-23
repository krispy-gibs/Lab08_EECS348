#include <stdio.h>
#include <ctype.h>   


double to_celsius(double v, char scale) {
    scale = (char)toupper((unsigned char)scale);
    if (scale == 'C'){
        return v;
    } 
    if (scale == 'F'){
        return (v - 32.0) * 5.0 / 9.0;
    }
    if (scale == 'K'){
        return v - 273.15;
    }
}


double from_celsius(double c, char scale) {
    scale = (char)toupper((unsigned char)scale);
    if (scale == 'C'){
        return c;
    } 
    if (scale == 'F'){
        return c * 9.0 / 5.0 + 32.0;
    } 
    if (scale == 'K'){
        return c + 273.15;
    }
    return c; 
}

const char* category_for_celsius(double c) {
    if (c < 0.0){
        return "Freezing";
    }
    else if (c < 10.0){
        return "Cold";
    }
    else if (c < 25.0){
        return "Mild";
    }
    else if (c < 35.0){
        return "Hot";
    }
    else return "Extreme Heat";
}

const char* advice_for_category(const char* cat) {
    if (cat[0] == 'F'){
        return "Wear a heavy jacket.";
    } 
    if (cat[0] == 'C' && cat[1] == 'o'){
        return "Wear a light jacket.";
    }       
    if (cat[0] == 'C' && cat[1] == 'o' && cat[2] == 'm'){
        return "A t-shirt is fine.";
    } 
    if (cat[0] == 'H'){
        return "Stay hydrated.";
    } return "Drink lots of water.";
    else return "Stay indoors and keep cool."; 
}

int main(void) {
    double value;
    char inScale, outScale;

    printf("Enter the temperature's value: ");
    if (scanf("%lf", &value) != 1) return 0;

    printf("Enter the original scale (C, F, or K): ");
    if (scanf(" %c", &inScale) != 1) return 0;

    printf("Enter the scale to convert to (C, F, or K): ");
    if (scanf(" %c", &outScale) != 1) return 0;

    inScale  = (char)toupper((unsigned char)inScale);
    outScale = (char)toupper((unsigned char)outScale);

    if ((inScale != 'C' && inScale != 'F' && inScale != 'K') ||
        (outScale != 'C' && outScale != 'F' && outScale != 'K')) {
        printf("Invalid scale. Use C, F, or K.\n");
        return 0;
    }


    double c = to_celsius(value, inScale);
  
    double converted = from_celsius(c, outScale);

    const char* cat = category_for_celsius(c);
    const char* tip = advice_for_category(cat);

    printf("Converted temperature: %.2f %c\n", converted, outScale);
    printf("Temperature category: %s\n", cat);
    printf("Weather advisory: %s\n", tip);

    return 0;
}

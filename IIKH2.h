/**
Six Components
    - Greeter
    - Plan Manager
    - Recipe Database
    - Date
    - Meal
    - Recipe

Greeter
    Display menu
    Recieves user input for menu selection
    Actions
        - Browse the database of recipes
        - Add a new recipe
        - Edit/Annotate a recipe
        - Review a plan for several meals
        - Create a plan of meals

Planner
    Makes user to select a sequence of dates for planning
    Makes user to edit an existing plan
    Associates with Date object

Recipe Database
    Actions
        - Maintain the Database of recipes
        - Allow the user to browse the database
        - Makes the user to edit/annotate an existing recipe
        - Makes the user to add a new recipe

Recipe
    Tasks
        - Maintains the list of ingredient/transformation algorithm
        - Know how to edit data values
        - Know how to interactively display itself on the output device
        - know how to print itself

Date
    User can edit specific meals
    User can annotate information abouts dates
    Print out grocery list for entire set of meals

Meal
    Holds information about a single meal
        - Allow user to interact with the recipe database to select individual recipes for meals
        - User sets number of people to be presents at meal, recipes are automatically scaled
        - Can produce grocery list for entire meal by combining grocery list from individual scaled recipes
**/

#include <iostream>

using namespace std;

class Recipe {
private:
    string name;
    string ingredient; //TODO 재료 이름-양-단위
    string transformation;
    string annotation;
public:
    Recipe();
    ~Recipe();
    void setRecipe(string name, string ingredient, string transformation, string annotation);
    //TODO get ingredient
    void printRecipe();
};

class Meal {
private:
    vector<Recipe> recipeList;
    int people;
public:
    Meal();
    ~Meal();
    void setMeal(vector<Recipe> &recipeList, int people);
    void printMeal(); //print grocery list
};

class Date {
private:
    string date;
    string annotation;
    vector<Meal> mealList;
public:
    Date();
    ~Date();
    void setDate(string date, string annotation, vector<Meal> &mealList);
    void printDate(); //print grocery list
};

class RecipeDatabase {
private:
    vector<Recipe> recipeList;
public:
    RecipeDatabase();
    ~RecipeDatabase();
    void insertRecipe(Recipe &recipe);
    void editRecipe(Recipe &source, Recipe &target);
    void deleteRecipe(Recipe &recipe);
    Recipe& searchRecipe(string name);
    void sortRecipe(); //sort by name
    void printList();
};

class Planner {
private:
    vector<Date> dateList;
public:
    Planner();
    ~Planner();
    void insertPlan(Date &date);
    void editPlan(Date &source, Date &target);
    void deletePlan(Date &date);
    Date& selectDate(string date);
    void printList();
};

class Greeter {
private:
    void insertRecipe();
    void editRecipe();
    void searchRecipe();
    void printRecipe();
    void insertPlan();
    void editPlan();
    void searchPlan();
    void printPlan();
public:
    Greeter();
    ~Greeter();
    void displayMenu();
};


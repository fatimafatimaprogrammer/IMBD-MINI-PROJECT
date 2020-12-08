/************************************************************************************************************
                                  "  DSA PRE MID TERM Project "

                                     IMBD_tOP5000_movies.csv
                                    Urooj Fatima Raza (289365)
                                      Kaynat Sajid (285091)
************************************************************************************************************/

#include <iostream>
#include <fstream>
#include<sstream>
#include<string>
#include<stdlib.h>

using namespace std;

class Movie ;
class MovieNode ;
class MoviesActorsActedIn ;
class MovieList;
class Actor ;
class ActorNode ;
class ActorList ;
class Director;
class DirectorNode;
class DirectorList;


class Movie {
public:
    string movie_title;
    unsigned short int director_facebook_likes;
    unsigned short int num_critics_for_reviews;
    string actor_1_name;
    int actor_1_facebook_likes;
    string actor_2_name;
    int actor_2_facebook_likes;
    string actor_3_name;
    int actor_3_facebook_likes;
    int gross;
    string genres;
    unsigned short int num_voted_users;
    unsigned short int cst_total_facebook_likes;
    string director_name;
    string color;
    unsigned short int facenumber_in_poster;
    string plot_keywords;
    string movie_imbd_link;
    unsigned short int num_user_for_reviews;
    string language;
    string country;
    string content_rating;
    int budget;
    unsigned short int title_year;
    float imdb_score;
    float aspect_ratio;
    unsigned short int movie_facebook_likes;
    int duration;

    //default constructor for movie
    Movie() {}


    //constructor with 28 parameters
    Movie(string movie_title, string genres, unsigned short int title_year, float imdb_score,string  director_name, unsigned short int director_facebook_likes, unsigned short int num_critics_for_reviews,
       int duration,string actor_1_name,int actor_1_facebook_likes, string actor_2_name,int actor_2_facebook_likes, string actor_3_name, int actor_3_facebook_likes
        ,int gross, unsigned short int num_voted_users, unsigned short int cst_total_facebook_likes, unsigned short int facenumber_in_poster,string plot_keywords,string movie_imbd_link, unsigned short int num_user_for_reviews,
       string  language, string country, string content_rating, int budget, float aspect_ratio, unsigned short int movie_facebook_likes, string color)
    {
        this->movie_title = movie_title;
        this->director_name = director_name;
        this->director_facebook_likes = director_facebook_likes;
        this->num_critics_for_reviews = num_critics_for_reviews;
        this->actor_1_name = actor_1_name;
        this->actor_1_facebook_likes = actor_1_facebook_likes;
        this->actor_2_name = actor_2_name;
        this->actor_2_facebook_likes = actor_2_facebook_likes;
        this->actor_3_name = actor_3_name;
        this->actor_3_facebook_likes = actor_3_facebook_likes;
        this->gross = gross;
        this->genres = genres;
        this->num_voted_users = num_voted_users;
        this->cst_total_facebook_likes = cst_total_facebook_likes;
        this->color = color;
        this->facenumber_in_poster = facenumber_in_poster;
        this->plot_keywords = plot_keywords;
        this->movie_imbd_link = movie_imbd_link;
        this->num_user_for_reviews = num_user_for_reviews;
        this->language = language;
        this->country = country;
        this->content_rating = content_rating;
        this->budget = budget;
        this->title_year = title_year;
        this->imdb_score = imdb_score;
        this->aspect_ratio = aspect_ratio;
        this->movie_facebook_likes = movie_facebook_likes;
        this->duration = duration;
    }
};

class MovieNode {
public:
    Movie data;
    MovieNode* next;
};

class MovieNodeIndexing {
public:
    Movie data;
    MovieNodeIndexing* next;

    MovieNodeIndexing() {
        next = NULL;
    }
};

class MovieNodeIndexingList
{
public:
    MovieNodeIndexing* start_indexing_list;
    MovieNodeIndexing* last_indexing_list;
    MovieNodeIndexing* loc_indexing_list;
    MovieNodeIndexing* ploc_indexing_list;

    //constructor
    MovieNodeIndexingList() {
        start_indexing_list = NULL;
        last_indexing_list = NULL;
    }

    bool isEmpty_Movie_Node_IndexingList_() {
        return (start_indexing_list == NULL);
    }
    //search nodes on basis of year
    void searchNode(unsigned short int year) {

        loc_indexing_list = start_indexing_list;
        ploc_indexing_list = NULL;

        while (loc_indexing_list != NULL && loc_indexing_list->data.title_year < year) {

            ploc_indexing_list = loc_indexing_list;
            loc_indexing_list = loc_indexing_list->next;
        }
        if (loc_indexing_list != NULL && loc_indexing_list->data.title_year >= year) {
            loc_indexing_list = NULL;
        }
    }

    //sort movie chronologically
    void Insert_sorted_chronologically(Movie movie) {
        MovieNodeIndexing* newnodeindex = new MovieNodeIndexing();
        newnodeindex->data = movie;
        searchNode(newnodeindex->data.title_year);
        if (loc_indexing_list != NULL) {
            newnodeindex->next = ploc_indexing_list->next;
            ploc_indexing_list->next = newnodeindex;
        }
        else {
            //insert at front
            if (ploc_indexing_list == NULL) {
                if (!(isEmpty_Movie_Node_IndexingList_()))
                    newnodeindex->next = start_indexing_list;
                else
                {
                    last_indexing_list = newnodeindex;
                    start_indexing_list = newnodeindex;
                }
            }//ends insert at front

            //insert at end
            else if (ploc_indexing_list == NULL) {
                if ((!isEmpty_Movie_Node_IndexingList_())) {
                    last_indexing_list->next = newnodeindex;
                }
                else
                {
                    start_indexing_list = newnodeindex;
                }
                last_indexing_list = newnodeindex;
            }//ends insert at end

            else
            { //insertion btw nodes
                newnodeindex->next = ploc_indexing_list->next;
                ploc_indexing_list->next = newnodeindex;
            }
        }
    }
};

class MoviesActorsActedin {
public:
    MovieNode* start_Actor_Movie_TITLE;
    MovieNode* last_Actor_Movie_TITLE;

    //constructor default
    MoviesActorsActedin() {
        start_Actor_Movie_TITLE = NULL;
        last_Actor_Movie_TITLE = NULL;
    }

    //actor nay koi movie nahi ki
    bool isEMPTY_movies_Actors_Acted_in() {
        return start_Actor_Movie_TITLE == NULL;
    }

    void Insert_movies_Actors_Acted_in(Movie obj) {
        MovieNode* newnode = new MovieNode;
        newnode->data = obj;

        if (!isEMPTY_movies_Actors_Acted_in()) {
            last_Actor_Movie_TITLE->next = newnode;
        }
        else {
            start_Actor_Movie_TITLE = newnode;
        }
        //yeh dono mein ayay gi tu efficency 
        last_Actor_Movie_TITLE = newnode;
    }

};

class Actor {
public:
    MoviesActorsActedin*  start_movie_acted_in;
    Movie actors_movie_obj;

    string actor_name;
    unsigned short int actor_facebook_likes;

    MovieNodeIndexingList* start_sorted_Actor_movie;

    Actor() {}

    Actor(string actor_name, unsigned short int actor_facebook_likes, Movie actors_movie_obj)
    {
        this->actor_name = actor_name;
        this->actor_facebook_likes = actor_facebook_likes;
        this->actors_movie_obj = actors_movie_obj;
       start_movie_acted_in = new MoviesActorsActedin;

       /*sorted list of of movies for each actor*/
       start_sorted_Actor_movie = new MovieNodeIndexingList;
    }

};

/*we have to maintain another linked list to store data of actors linked list kiss say banti hai
node say*/

class ActorNode {
public:
    Actor data;//iss kay data type ki type hai actor
    ActorNode* next;

    //constructor
    ActorNode() {
        next = NULL;
    }
};

class ActorList {
public:
    ActorNode* start_actor;
    ActorNode* last_actor;// it stores the address of starting node in list
    ActorNode* loc_actor;
    ActorNode* ploc_actor;

    ActorList() {
        start_actor = NULL;
        last_actor = NULL;
    }

    bool isEmpty_ActorList() {
        return start_actor == NULL;
    }

    bool Search_Actor(string Actor_name) {
        if (isEmpty_ActorList()) {
            return false;
        }

        ActorNode* temp = start_actor;
        while (temp != NULL) {
            if (Actor_name == temp->data.actor_name) {
                loc_actor = temp;
                return true;
            }
            temp = temp->next;
        }

        return false;
    }

    void updateMovie_List(Movie movie_obj) {
        loc_actor->data.start_movie_acted_in->Insert_movies_Actors_Acted_in(movie_obj);
        loc_actor->data.start_sorted_Actor_movie->Insert_sorted_chronologically(movie_obj);

    }

    void insert_actorNode(Actor  ActorObject, Movie movie_object) {
        //if actor already worked in other movies then update by adding other movie to that actor
        if (Search_Actor(ActorObject.actor_name)) {
            updateMovie_List(movie_object);
            return;
        }
        //if actor has not performed in any previous movie then create newnode and store actor
        ActorNode* newactornode = new ActorNode();
        newactornode->data = ActorObject;
        newactornode->data.start_movie_acted_in->Insert_movies_Actors_Acted_in(movie_object);

        /*for chronologically sorted list*/
        newactornode->data.start_sorted_Actor_movie->Insert_sorted_chronologically(movie_object);

        /*if actorlist is empty */
        if (start_actor == NULL)
        {
            start_actor = newactornode;
            last_actor = newactornode;
        }
        else/*if list is not empty*/
        {
            last_actor->next = newactornode;
            last_actor = newactornode;
        }
    }//ends insert
};

//----------------------------------------------------------------------
class MoviesDirectedinList {
public:
    MovieNode* start_Director;
    MovieNode* last_Director;
    //CONSTRUCTOR
    MoviesDirectedinList() {
        start_Director = NULL;
        last_Director = NULL;
    }

    //isempty 
    bool isEmpty_Movies_Directed_in_List() {
        return start_Director == NULL;
    }

    void insert_Movies_Directed_in_List(Movie obj_director) {
        MovieNode* newnode = new MovieNode;
        newnode->data = obj_director;
        if (isEmpty_Movies_Directed_in_List()) {
            start_Director = newnode;
        }
        else {
            last_Director->next = newnode;
        }
        last_Director = newnode;
    }


};

class Director {
public:
    string director_name;
    unsigned short int director_facebook_likes;

    MoviesDirectedinList* startMovie_diretor_list;
    Movie obj_director;

    Director() {}

    Director(string director_name, unsigned short int director_facebook_likes, Movie obj_director) {
        this->director_name = director_name;
        this->director_facebook_likes = director_facebook_likes;
        this->obj_director = obj_director;
        startMovie_diretor_list = new MoviesDirectedinList();
    }
};

class DirectorNode {
public:
    Director data;
    DirectorNode* next;

    DirectorNode() {
        next = NULL;
    }
};

class DirectorList {
public:
    DirectorNode* start_director_list;
    DirectorNode* last_director_list;
    DirectorNode* loc_director_list;
    DirectorNode* ploc_director_list;

    MoviesDirectedinList* start_movies_directed;

    //constructor
    DirectorList() {
        start_director_list = NULL;
        last_director_list = NULL;
    }

    //IF EMPTY LIST 
    bool isEmpty_DirectorList() {
        return start_director_list == NULL;
    }

    bool Search_DirectorList(string director_name) {
        if (isEmpty_DirectorList()) {
            return false;
        }

        DirectorNode* temp = start_director_list;
        while (temp != NULL) {
            if (director_name == temp->data.director_name) {
                loc_director_list = temp;
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    //if director directed any other movie so update director data and adds movie
    void update_Director_List(Movie obj_director) {
        loc_director_list->data.startMovie_diretor_list->insert_Movies_Directed_in_List(obj_director);
    }

    //now finally inserting 
    void insert_Director_List(Director director_obj, Movie obj_movie) {
        if (Search_DirectorList(director_obj.director_name)) {
            update_Director_List(obj_movie);
        }

        //create new node if director is not directed any previous movies
        DirectorNode* newnode = new DirectorNode;
        newnode->data = director_obj;
        newnode->data.startMovie_diretor_list->insert_Movies_Directed_in_List(obj_movie);

        if (isEmpty_DirectorList()) {
            start_director_list = newnode;

        }
        else
        {
            last_director_list->next = newnode;
        }
        last_director_list = newnode;
    }

};

//-------------------------------------------------------------------------
class MovieRatingWiseList
{
public:
    MovieNode* start;
    MovieNode* last;
    MovieNode* loc;
    MovieNode* ploc;

    void InsertAtStartRatingWise(Movie movie)
    {
        MovieNode* newnode = new MovieNode();
        newnode->data = movie;

        /*case :if lit is empty */
        if (start == nullptr) {
            start = newnode;
            last = newnode;
        }
        else {
            /*case: make newnode start*/
            newnode->next = start;
            start= newnode;
        }
    }

    void InsertAtEndRatingWise(Movie movie)
    {
        MovieNode* newnode = new MovieNode();
        newnode->data = movie;

        if (start == nullptr) {
            start = newnode;
            last = newnode;
        }
        else {
            last->next = newnode;
            last = newnode;
        }
    }

    void SearchRatingWise(float score)
    {
        loc = start;
        ploc = nullptr;

        while (loc != nullptr && loc->data.imdb_score < score) {
            ploc = loc;
            loc = loc->next;
        }


    }

    void InsertSortedRatingWise(Movie movieobj)
    {
        SearchRatingWise(movieobj.imdb_score);

        if (ploc == nullptr) {
            InsertAtStartRatingWise(movieobj);
            return;
        }
        else {
            if (ploc->next == nullptr) {
                InsertAtEndRatingWise(movieobj);
                return;
            }
            else {
                MovieNode* newnode = new MovieNode();
                newnode->data = movieobj;

                newnode->next = ploc->next;
                ploc->next = newnode;
            }
        }

    }

};


class MovieList {
public:
    MovieNode* start_movie;
    MovieNode* last_movie;
    MovieNode* loc = NULL;
    MovieNode* Ploc = NULL;
    //MovieNode* loc_movie;
    //MovieNode* ploc_movie;// it stores the address of starting node in list

    /* objects for Actor and ActorList*/
    Actor* obj_for_actor1;
    Actor* obj_for_actor2;
    Actor* obj_for_actor3;

    ActorList* actorList_obj = new ActorList();

    /*objects for Director and DirectorList*/
    Director* object_Director;

    DirectorList* director_list_object = new DirectorList();

    /*objects for movie_INDEX_node*/
    MovieNodeIndexing* movieIndex;

    MovieNodeIndexingList* MovieIndexList = new MovieNodeIndexingList();


public:
    MovieList() {
        start_movie = NULL;
        last_movie = NULL;
        loc = NULL;
        Ploc = NULL;
    }
    bool isEmpty_movielist() {
        return start_movie == NULL;
    }

    void insert_movieNode(Movie  movieObject) {
        MovieNode* newmovienode = new MovieNode();
        newmovienode->data = movieObject;
        if (start_movie == NULL)
        {
            start_movie = newmovienode;
            last_movie = newmovienode;
        }
        else
        {
            last_movie->next = newmovienode;
            last_movie = newmovienode;
        }
        // last_movie = newmovienode;
    }//ends insert

    void parserFunction() {

        //defining all attributes to stores all 28  fields of IMBD movies 
        string movie_title;
        string director_name;
        unsigned short int director_facebook_likes;
        unsigned short int num_critics_for_reviews;
        string actor_1_name;
        int actor_1_facebook_likes;
        string actor_2_name;
        int actor_2_facebook_likes;
        string actor_3_name;
        int actor_3_facebook_likes;
        int gross;
        string genres;
        unsigned short int num_voted_users;
        unsigned short int cst_total_facebook_likes;
        string color;
        unsigned short int facenumber_in_poster;
        string plot_keywords;
        string movie_imbd_link;
        unsigned short int num_user_for_reviews;
        string language;
        string country;
        string content_rating;
        int budget;
        unsigned short int title_year;
        float imdb_score;
        float aspect_ratio;
        unsigned short int movie_facebook_likes;
        int duration;

        //reading .csv file
        ifstream ip("IMDB_Top5000-SEECS.csv");

        /*case : if file failed to open */
        if (!ip.is_open()) {
            cout << "file failed to open" << endl;
        }

        /*case : if file open sucessfully*/
        else {
            cout << "file opened \n";
            /*reading line 1 */
            string line1;
            string line2;

            /*variable for temporarly storing value which further converted to other */
            string temp;
            int i = 0;

            /*leaving the line 1 with names of titles of attributes as it is */
            getline(ip, line1);
            while (getline(ip, line2)) {
                stringstream ss(line2);
                //*******************attribute#1
                getline(ss, movie_title, 'Â');
                getline(ss, temp, ',');
                //*******************attribute#2
                getline(ss, genres, ',');
                //*******************attribute#3
                getline(ss, temp, ',');
                stringstream tyear(temp);
                tyear >> title_year;
                //*******************attribute#4
                getline(ss, temp, ',');
                stringstream score(temp);
                score >> imdb_score;
                //*******************attribute#5
                getline(ss, director_name, ',');
                //*******************attribute#6
                getline(ss, temp, ',');
                stringstream d_fb_likes(temp);
                d_fb_likes >> director_facebook_likes;
                //*******************attribute#7
                getline(ss, temp, ',');
                stringstream no_critics(temp);
                no_critics >> num_critics_for_reviews;
                //*******************attribute#8
                getline(ss, temp, ',');
                stringstream dur(temp);
                dur >> duration;
                //*******************attribute#9
                getline(ss, actor_1_name, ',');
                //*******************attribute#10
                getline(ss, temp, ',');
                stringstream a1fb_likes(temp);
                a1fb_likes >> actor_1_facebook_likes;
                //*******************attribute#11
                getline(ss, actor_2_name, ',');
                //*******************attribute#12
                getline(ss, temp, ',');
                stringstream a2fb_likes(temp);
                a2fb_likes >> actor_2_facebook_likes;
                //*******************attribute#13
                getline(ss, actor_3_name, ',');
                //*******************attribute#14
                getline(ss, temp, ',');
                stringstream a3fb_likes(temp);
                a3fb_likes >> actor_3_facebook_likes;
                //*******************attribute#15
                getline(ss, temp, ',');
                stringstream gros(temp);
                gros >> gross;
                //*******************attribute#16
                getline(ss, temp, ',');
                stringstream voted_user(temp);
                voted_user >> num_voted_users;
                //*******************attribute#17
                getline(ss, temp, ',');
                stringstream total_fb_likes(temp);
                total_fb_likes >> cst_total_facebook_likes;
                //*******************attribute#18
                getline(ss, temp, ',');
                stringstream fb_poster(temp);
                fb_poster >> facenumber_in_poster;
                //*******************attribute#19
                getline(ss, plot_keywords, ',');
                //*******************attribute#20
                getline(ss, movie_imbd_link, ',');
                //*******************attribute#21
                getline(ss, temp, ',');
                stringstream reviews(temp);
                reviews >> num_user_for_reviews;
                //*******************attribute#22
                getline(ss, language, ',');
                //*******************attribute#23
                getline(ss, country, ',');
                //*******************attribute#24
                getline(ss, temp, ',');
                stringstream rating(temp);
                rating >> content_rating;
                //*******************attribute#25
                getline(ss, temp, ',');
                stringstream budg(temp);
                budg >> budget;
                //*******************attribute#26
                getline(ss, temp, ',');
                stringstream ratio(temp);
                ratio >> aspect_ratio;
                //*******************attribute#27
                getline(ss, temp, ',');
                stringstream mov_fb_likes(temp);
                mov_fb_likes >> movie_facebook_likes;
                //*******************attribute#28
                getline(ss, color, ',');


                /*************** Movie constructor ***************************/
                Movie* obj = new Movie(movie_title, genres, title_year, imdb_score, director_name, director_facebook_likes, num_critics_for_reviews,
                    duration, actor_1_name, actor_1_facebook_likes, actor_2_name, actor_2_facebook_likes, actor_3_name, actor_3_facebook_likes
                    , gross, num_voted_users, cst_total_facebook_likes, facenumber_in_poster, plot_keywords, movie_imbd_link, num_user_for_reviews,
                    language, country, content_rating, budget, aspect_ratio, movie_facebook_likes, color);

                /*constructors for actors */
                obj_for_actor1 = new Actor(actor_1_name, actor_1_facebook_likes, *obj);
                obj_for_actor2 = new Actor(actor_2_name, actor_2_facebook_likes, *obj);
                obj_for_actor3 = new Actor(actor_3_name, actor_3_facebook_likes, *obj);
                /*inserting data into actor lists*/
                actorList_obj->insert_actorNode(*obj_for_actor1, *obj);
                actorList_obj->insert_actorNode(*obj_for_actor2, *obj);
                actorList_obj->insert_actorNode(*obj_for_actor3, *obj);

                /*constructor for director*/
                object_Director = new Director(director_name, director_facebook_likes, *obj);
                /*inserting data into director list*/
                director_list_object->insert_Director_List(*object_Director, *obj);

                /*inserting data year wise into movie_Index_list*/
                movieIndex = new MovieNodeIndexing();
                MovieIndexList->Insert_sorted_chronologically(*obj);

                /*insert data rating wise in list*/
                InsertSortedRatingWise(*obj);
            }
            cout << endl;
            /*clossing of file*/
            ip.close();
        }
    }

    void InsertAtStartRatingWise(Movie movie)
    {
        MovieNode* newnode = new MovieNode();
        newnode->data = movie;

        /*case :if lit is empty */
        if (start_movie == nullptr) {
            start_movie = newnode;
            last_movie = newnode;
        }
        else {
            /*case: make newnode start*/
            newnode->next = start_movie;
            start_movie = newnode;
        }
    }

    void InsertAtEndRatingWise(Movie movie)
    {
        MovieNode* newnode = new MovieNode();
        newnode->data = movie;

        if (start_movie == nullptr) {
            start_movie = newnode;
            last_movie = newnode;
        }
        else {
            last_movie->next = newnode;
            last_movie = newnode;
        }
    }

    void SearchRatingWise(float score)
    {
        loc = start_movie;
        Ploc = nullptr;

        while (loc != nullptr && loc->data.imdb_score < score) {
            Ploc = loc;
            loc = loc->next;
        }


    }

    void InsertSortedRatingWise(Movie movieobj)
    {
        SearchRatingWise(movieobj.imdb_score);

        if (Ploc == nullptr) {
            InsertAtStartRatingWise(movieobj);
            return;
        }
        else {
            if (Ploc->next == nullptr) {
                InsertAtEndRatingWise(movieobj);
                return;
            }
            else {
                MovieNode* newnode = new MovieNode();
                newnode->data = movieobj;

                newnode->next = Ploc->next;
                Ploc->next = newnode;
            }
        }

    }

    void print_Movie_list() {
        /*case : if list is not empty*/
        if (!isEmpty_movielist()) {
            /*creating new node*/
            MovieNode* temp = start_movie;
            int index = 0;  //for counting
            while (temp != NULL)
            {
                /*printing all data*/
                cout << ++index << " ) "
                    << "Title  " << temp->data.movie_title << "\t"
                    << "genre   " << temp->data.genres << "\t"
                    << "title year   " << temp->data.title_year << "\t"
                    << "IMDB score  " << temp->data.imdb_score << "\n"
                    << "Director name   " << temp->data.director_name << "\t"
                    << "Director Facebook likes" << temp->data.director_facebook_likes << "\t"
                    << "num critic for reviews      " << temp->data.num_critics_for_reviews << "\t"
                    << "duration  " << temp->data.duration << "\n"
                    << "Actor 1 name   " << temp->data.actor_1_name << "\t"
                    << "Actor 1 fb likes    " << temp->data.actor_1_facebook_likes << "\t"
                    << "Actor 2 name   " << temp->data.actor_2_name << "\t"
                    << "Actor 2 fb likes    " << temp->data.actor_2_facebook_likes << "\n"
                    << "Actor 3 name    " << temp->data.actor_3_name << "\t"
                    << "Actor 3 fb likes    " << temp->data.actor_3_facebook_likes << "\t"
                    << "Gross   " << temp->data.gross << "\t"
                    << "num of voted users  " << temp->data.num_voted_users << "\n"
                    << "cast total fb likes     " << temp->data.cst_total_facebook_likes << "\t"
                    << "facenumber in poster    " << temp->data.facenumber_in_poster << "\t"
                    << "plot keywords   " << temp->data.plot_keywords << "\t"
                    << "movie imdb link     " << temp->data.movie_imbd_link << "\n"
                    << "num users for reviews   " << temp->data.num_user_for_reviews << "\t"
                    << "language    " << temp->data.language << "\t"
                    << "country     " << temp->data.country << "\t"
                    << "content rating      " << temp->data.content_rating << "\n"
                    << "budget  " << temp->data.budget << "\t"
                    << "aspect ratio    " << temp->data.aspect_ratio << "\t"
                    << "movie fb likes  " << temp->data.movie_facebook_likes << "\t"
                    << "colour     " << temp->data.color << "\t"
                    << endl << endl;
                /*traversing through the whole list*/
                temp = temp->next;
            }
            cout << endl;
            return;
        }
    }//ends print list

    void print_Actor_List() {

        if (!actorList_obj->isEmpty_ActorList()) {

            ActorNode* temp = actorList_obj->start_actor;
            int index = 0;
            while (temp != NULL) {
                cout << ++index << " )  "
                    << "Actor Name : " << temp->data.actor_name << "\t\t\t"
                    << "movie title : " << temp->data.start_movie_acted_in->start_Actor_Movie_TITLE->data.movie_title
                    << "Actor Facebook Likes : " << temp->data.actor_facebook_likes << endl;
                temp = temp->next;
            }
            return;
        }
        else {
            cout << "ActorList is Empty!!!!!!!!!!!!" << endl;
        }

    }

    void print_Director_List() {

        if (!director_list_object->isEmpty_DirectorList()) {

            DirectorNode* temp = director_list_object->start_director_list;

            while (temp != NULL) {
                cout
                    << "Director Name: " << temp->data.director_name << "\n"
                    << "Director Facebook Likes: " << temp->data.director_facebook_likes << "\n\n";
                temp = temp->next;
            }
            return;
        }
        else {

            cout << "Director List is Empty!!!!!!!!!!!!!!!!!!!!!!" << endl;
        }
    }

    //=========================== Actor Function # 1 =============================================

    /*************************************
    Time Complexity: O(N^2)
    *************************************/

   //searches actor name to print actor profile
    void SearchActorProfile(string actor_name) {
        if (!(actorList_obj->isEmpty_ActorList()))
        {
            //finds  the actor in the list then calls print fun using actor's sorted list
            ActorNode* temp = actorList_obj->start_actor;
            while (temp != NULL) {
                if (actor_name == temp->data.actor_name) {
                    print_Actor_movielist(actor_name, temp->data.start_sorted_Actor_movie);
                    return;
                }
                temp = temp->next;
            }//ends while
            cout << "actor not found";
            return;
        }
        else
            cout << "Actor List is empty";
        return;

    }//ends fun

    //prints the actor's profile
    void print_Actor_movielist(string actor_name, MovieNodeIndexingList* searched_actor) {
        MovieNodeIndexing* temp = searched_actor->start_indexing_list;
        int count = 0; //checks how many movies an actor has done
        cout << "ActorName:" << actor_name << endl;
        //searches through the entire list of movies an actor has acted in,and prints relevant data
        while (temp != NULL) {
            count++;
            cout << "Movie Title\t\t" << temp->data.movie_title
                << "\nRelease Year\t\t" << temp->data.title_year << endl;

            temp = temp->next;
        }
        cout << " Total movies acted in;" << count;
    }

    //=========================== Actor Function # 2 =============================================

    /*************************************
    Time Complexity: O(N^2)
    *************************************/

    //***actor task 2*****//
    //first we search whether the actor exists or not
    void SearchCoActor(string actorname) {
        //checks if actor list is empty or not
        if (!(actorList_obj->isEmpty_ActorList())) {

            //checks actor name in actorlist
            ActorNode* temp = actorList_obj->start_actor;
            while (temp != NULL) {
                if (temp->data.actor_name == actorname) {

                    //if name exists,then calls print to show coActors
                    printCoActor(actorname, temp->data.start_movie_acted_in);
                    return;
                }
                //else checks for next node
                temp = temp->next;
            }
            return;
        }
        else cout << "Actor List is empty";
    }//ends fun searchCoActor

    /***print coactor fun**/

    void printCoActor(string actor,MoviesActorsActedin* searchActorNode) {
        cout << " Actor Name : \" " << actor << " \" his co_actors are : \n";
        //starts checking the entire list of movies actor has acted in
        //and prints all coactors in that movie
        MovieNode* temp = searchActorNode->start_Actor_Movie_TITLE;
        int countCoActors = 0;
        while (temp != NULL) {
            cout << "Movie :\t\t\t" << temp->data.movie_title << endl;
            if (temp->data.actor_1_name != actor)
            {
                cout << "Coactor " << countCoActors + 1 << ":\t\t" << temp->data.actor_1_name << endl;
                countCoActors++;
            }
            if (temp->data.actor_2_name != actor)
            {
                cout << "Coactor " << countCoActors + 1 << ":\t\t" << temp->data.actor_2_name << endl;
                countCoActors++;
            }
            if (temp->data.actor_3_name != actor)
            {
                cout << "Coactor " << countCoActors + 1 << ":\t\t" << temp->data.actor_3_name << endl;
                countCoActors++;
            }
            temp = temp->next;
        }//ends while
        cout << "Total no of coactors: " << countCoActors<<endl;
    }//ends fun print

    //=========================== Actor Function # 3 =============================================

     /*************************************
    Time Complexity: O(N^3)
    *************************************/

    //***actor task 3*****//
    //first we search whether the actor exists or not
    void SearchUniqueCoActor(string actorname) {
        //checks if actor list is empty or not
        if (!(actorList_obj->isEmpty_ActorList())) {

            //checks actor name in actorlist
            ActorNode* temp = actorList_obj->start_actor;

            while (temp != NULL) {
                if (temp->data.actor_name == actorname) {

                    //if name exists,then calls print to show coActors
                    PrintUniqueCoActor(actorname, temp->data.start_movie_acted_in);
                    return;
                }
                //else checks for next node
                temp = temp->next;
            }
            return;
        }
        else cout << "Actor List is empty";
    }//ends fun searchCoActor

    /***print coactor fun**/
    void PrintUniqueCoActor(string actor, MoviesActorsActedin* ActorNode) {
        //starts checking the entire list of movies actor has acted in
        //and prints all coactors in that movie
        MovieNode* temp = ActorNode->start_Actor_Movie_TITLE;
        int index = 0;
        int count = 1;
        string* CoActorArray = new string[100];
        while (temp != NULL) {
            cout << "Movie :\t\t\t" << temp->data.movie_title << endl;
            if (count == 1) {
                CoActorArray[index++] = temp->data.actor_1_name;
                CoActorArray[index++] = temp->data.actor_2_name;
                CoActorArray[index++] = temp->data.actor_3_name;
                count++;

            }
            else {
                if (actor != temp->data.actor_1_name && isCoActorUnique(CoActorArray, index, actor))
                {
                    CoActorArray[index++] = temp->data.actor_1_name;
                    cout << "CoActor:\t\t" << temp->data.actor_1_name << "\nMovie\t\t" << temp->data.movie_title << endl;
                }
                if (actor != temp->data.actor_2_name && isCoActorUnique(CoActorArray, index, actor))
                {
                    CoActorArray[index++] = temp->data.actor_2_name;
                    cout << "CoActor:\t\t" << temp->data.actor_2_name << "\nMovie\t\t" << temp->data.movie_title << endl;
                }
                if (actor != temp->data.actor_3_name && isCoActorUnique(CoActorArray, index, actor))
                {
                    CoActorArray[index++] = temp->data.actor_3_name;
                    cout << "CoActor:\t\t" << temp->data.actor_3_name << "\nMovie\t\t" << temp->data.movie_title << endl;
                }
                count++;
            }

            temp = temp->next;
        }//ends while

    }//ends fun print

    bool isCoActorUnique(string* array, int index, string actorname) {
        for (int i = 0; i <= index; i++) {
            if (actorname == array[i])
                return false;
        }
        return true;
    }

    //=========================== Actor Function # 4 =============================================

     /*************************************
    Time Complexity: O(N^2)
    *************************************/

     //it first searches the whether actor exists pr not, 
    //then finds the coactor of that actor
    void SearchCoActorsOfCoActor(string actorname) {
        if (!(actorList_obj->isEmpty_ActorList())) {
            ActorNode* temp = actorList_obj->start_actor;
            //traverses whole list and calls print fun if coactor is found
            while (temp != NULL) {
                if (actorname == temp->data.actor_name) {
                    PrintCoActorsOfCoActor(actorname, temp->data.start_movie_acted_in);
                    return;
                }//ends if
                temp = temp->next;
            }//ends while
        }//ends if
        return;
    }//ends searchCoActorsOfCoActor

    //PrintCoActorsOfCoActor fun first checks coactor of an actor
    //then calls searchcoactor fun to print coactors of that coactor 
    void PrintCoActorsOfCoActor(string actorname, MoviesActorsActedin* actornode) {
        MovieNode* temp = actornode->start_Actor_Movie_TITLE;
        while (temp != NULL) {
            int countCoActor = 0;
            cout << "Movie :\t\t" << temp->data.movie_title << endl;
            //searches coactor
            if (actorname != temp->data.actor_1_name) {
                countCoActor++;
                cout << "CoActor:\t" << temp->data.actor_1_name << endl;
                cout << "Co CoActors:\t"<<endl;
                //calls fun to print coactors of coactor
                SearchCoActor(temp->data.actor_1_name);
            }

            if (actorname != temp->data.actor_2_name) {
                countCoActor++;
                cout << "CoActor:\t" << temp->data.actor_2_name << endl;
                cout << "Co CoActors:\t"<<endl;
                //calls fun to print coactors of coactor
                SearchCoActor(temp->data.actor_2_name);
            }

            if (actorname != temp->data.actor_3_name) {
                countCoActor++;
                cout << "CoActor:\t" << temp->data.actor_3_name << endl;
                cout << "Co CoActors:\t"<<endl;
                //calls fun to print coactors of coactor
                SearchCoActor(temp->data.actor_3_name);
            }
            temp = temp->next;
        }//ends while
    }//ends PrintCoActorsOfCoActor fun

    //=========================== Actor Function # 5 =============================================

    /*************************************
    Time Complexity: O(N^2)
    *************************************/

    /*Checks whether A and B are co-actors or not?*/

    void print_co_actors_or_not(string actor_A, string actor_B) {

        // checking the actor list if its not empty /

        if (!actorList_obj->isEmpty_ActorList()) {

            ActorNode* temp = actorList_obj->start_actor;

            while (temp != NULL) {
                if (actor_A == temp->data.actor_name || actor_B == temp->data.actor_name) {
                    search_co_actors_or_not(actor_A, actor_B, temp->data.start_movie_acted_in);
                    return;
   
                }

                temp = temp->next;
            }//ends while
         cout << "Actor_A \" " << actor_A << " \"and Actor_B \" " << actor_B << " \" are both CO_ACTORS .............\n\n";
        }
        else
        {
            cout << "List is Empty\n";
            return;
        }
    }

    void search_co_actors_or_not(string Actor_A, string Actor_B, MoviesActorsActedin* actor_movie) {
        MovieNode* temp = actor_movie->start_Actor_Movie_TITLE;

        /* Traversing through the movie list and checking if it is equal to any of the 3 actors acted in that movie */
        while (temp != NULL) {
            if ((Actor_A == temp->data.actor_1_name || Actor_A == temp->data.actor_2_name || Actor_A == temp->data.actor_3_name) &&
                (Actor_B == temp->data.actor_1_name || Actor_B == temp->data.actor_2_name || Actor_B == temp->data.actor_3_name))
            {
                cout << "Actor_A \" " << Actor_A << " \"and Actor_B \" " << Actor_B << " \" are  CO_ACTORS \n\n" << "\nAND acted in movie : \" "
                    << temp->data.movie_title << "\n\n";
                //return;
            }
            temp = temp->next;
        }
    }
   


    //=========================== Director Function # 1 =============================================

    /*************************************
    Time Complexity: O(N^2)
    *************************************/

    /*Prints all movies a director has directed.*/
    void search_director(string director_name) {
        if (!director_list_object->isEmpty_DirectorList()) {
            DirectorNode* Temp = director_list_object->start_director_list;

            while (Temp != NULL) {
                if (director_name == Temp->data.director_name) {
                    cout << "director found !!!!\n\n";
                    print_director_Movie_list(director_name, Temp->data.startMovie_diretor_list);
                    return;
                }
                Temp = Temp->next;
            }
            cout << "director not found !!" << endl;
        }
        cout << "list is empty!!!" << endl;
    }

    void print_director_Movie_list(string directorName, MoviesDirectedinList* directed_searched) {
        MovieNode* temp = directed_searched->start_Director;
        int no_of_movies_directed = 0;
        cout << "Director : \" " << directorName << " \" directed movies are : " << endl << endl;

        while (temp != NULL)
        {
            cout << ++no_of_movies_directed << " ) "
                << temp->data.movie_title << endl;

            temp = temp->next;
        }
        cout << "All movies directed by : " << directorName << " are : " << no_of_movies_directed;
    }

    //=========================== Director Function # 2 =============================================

    /*************************************
    Time Complexity: O(N)
    *************************************/

    /*Print directors who have directed movies of a certain genre*/

    void search_director_on_basis_of_genre(string genre) {
        if (!isEmpty_movielist()) {
            MovieNode* temp = start_movie;
            int genre_count = 0;
            while (temp != NULL) {
                /*if  small string(genre) is subset of main string so it returns true */
                if (strstr(temp->data.genres.c_str(), genre.c_str()))
                {
                    cout << ++genre_count << " ) "
                        << "Director Name : " << temp->data.director_name << "\n"
                        << "Movie_Title : " << temp->data.movie_title << "\n\n";
                }
                temp = temp->next;
            }
            return;
        }
        else {
            /*case when list is empty*/
            cout << "the movie list is empty\n";
        }
    }

    //=========================== Movie Function # 1 =============================================

    /*************************************
    Time Complexity: O(N)
    *************************************/

    /*Searches the movies list for the inserted title.
    If found prints information related to a movie such as its full title, release year, rating, duration, actors, director etc.*/
    void search_by_title(string Movie_title)
    {
        if (!isEmpty_movielist()) {
            MovieNode* temp = start_movie;
            while (temp != NULL)
            {
                if (temp->data.movie_title == Movie_title) {
                    cout
                        << "Title : " << temp->data.movie_title << "\n"
                        << "genre   : " << temp->data.genres << "\n"
                        << "title year :    " << temp->data.title_year << "\n"
                        << "IMDB score  : " << temp->data.imdb_score << "\n"
                        << "Director name  : " << temp->data.director_name << "\n"
                        << "Director Facebook likes  : " << temp->data.director_facebook_likes << "\n"
                        << "num critic for reviews  :  " << temp->data.num_critics_for_reviews << "\n"
                        << "duration  :  " << temp->data.duration << "\n"
                        << "Actor 1 name  :  " << temp->data.actor_1_name << "\n"
                        << "Actor 1 fb likes   : " << temp->data.actor_1_facebook_likes << "\n"
                        << "Actor 2 name  : " << temp->data.actor_2_name << "\n"
                        << "Actor 2 fb likes  :  " << temp->data.actor_2_facebook_likes << "\n"
                        << "Actor 3 name  :  " << temp->data.actor_3_name << "\n"
                        << "Actor 3 fb likes  :  " << temp->data.actor_3_facebook_likes << "\t"
                        << "Gross  : " << temp->data.gross << "\n"
                        << "num of voted users : " << temp->data.num_voted_users << "\n"
                        << "cast total fb likes   :  " << temp->data.cst_total_facebook_likes << "\n"
                        << "facenumber in poster   : " << temp->data.facenumber_in_poster << "\n"
                        << "plot keywords  : " << temp->data.plot_keywords << "\n"
                        << "movie imdb link  :   " << temp->data.movie_imbd_link << "\n"
                        << "num users for reviews  :  " << temp->data.num_user_for_reviews << "\n"
                        << "language  :  " << temp->data.language << "\n"
                        << "country    :  " << temp->data.country << "\n"
                        << "content rating   :   " << temp->data.content_rating << "\n"
                        << "budget :  " << temp->data.budget << "\n"
                        << "aspect ratio  :  " << temp->data.aspect_ratio << "\n"
                        << "movie fb likes : " << temp->data.movie_facebook_likes << "\n"
                        << "colour   :  " << temp->data.color << "\n"
                        << endl << endl;
                }
                temp = temp->next;
            }
        }

    }

    //=========================== Movie Function # 2 =============================================

    /*************************************
    Time Complexity: O(N)
    *************************************/

    /*Prints all movie titles released in the given year. You may store a year-wise index of all movie titles separately.*/
    void search_by_year(unsigned short int year) {
        if (!isEmpty_movielist()) 
        {
            MovieNode* temp = start_movie;
            int count = 0;
            while (temp != NULL)
            {
                if (temp->data.title_year == year) 
                {
                    cout << ++count << " ) "
                        << "Title : \t" << temp->data.movie_title << "\n";
                }
                temp = temp->next;
            }
            cout << endl;
        }
    }


    //=========================== Movie Function # 3 =============================================

    /*************************************
    Time Complexity: O(N)
    *************************************/

      /*Print movies year-wise*/
    void searchMoviesYearWise(){
        if (!MovieIndexList->isEmpty_Movie_Node_IndexingList_()) 
        {

            MovieNodeIndexing* temp = MovieIndexList->start_indexing_list;
            int index = 0;
            while (temp != NULL) {
                cout << ++index << " )  "
                    << "Year : \t" << temp->data.title_year << endl
                    << "movie title : \t" << temp->data.movie_title << endl<<endl;
                temp = temp->next;
            }
            return;
        }
        else 
        {
            cout << "List is Empty!!!!!!!!!!!!" << endl;
        }

    }

    //=========================== Movie Function # 4 =============================================

    /*************************************
    Time Complexity: O(N)
    *************************************/

    /*Search movies based on genre*/
    void search_movies_on_basis_of_genres(string genres) {
        if (!isEmpty_movielist()) {
            MovieNode* temp = start_movie;
            int genre_count = 0;
            cout << "Movies for  the genre \" " << genres << " \" are : \n\n";
            while (temp != NULL) {
                /*if  small string(genre) is subset of main string so it returns true */
                if (strstr(temp->data.genres.c_str(), genres.c_str()))
                {
                    cout << ++genre_count << " ) "
                        << "Movie_Title : " << temp->data.movie_title << "\n\n";
                }
                temp = temp->next;
            }
            return;
        }
        else {
            /*case when list is empty*/
            cout << "the movie list is empty\n";
        }
    }


    //=========================== movie Function # 5 =============================================
     /*Print movies rating-wise*/

    void PrintMoviesRatingWise()
    {
        MovieNode* Temp = start_movie;
        int count=0;
        while (Temp != NULL) {
            cout << ++count << " ) "
                << "movie title : \t" << Temp->data.movie_title << "\n"
                << "imbd score : \t" << Temp->data.imdb_score << "\n"
                << endl;
            Temp = Temp->next;
        }
        
    }

    /*************************************************************************************************/
    void PrintMoviesrecursively()
    {
        MovieNode* Temp = start_movie;
        int count = 0;
        PrintMoviesRatingWiserecursivelly(Temp, count);
    }

    void PrintMoviesRatingWiserecursivelly(MovieNode* temp,int count)
    {
        if (temp->next == NULL) {
            return;
       }
        else{
            cout << ++count << " ) "
                << "movie title : \t" << temp->data.movie_title << "\n"
                << "imbd score : \t" << temp->data.imdb_score << "\n"
                << endl;
        }
        PrintMoviesRatingWiserecursivelly(temp->next, count);
    }


    //=========================== movie Function # 6 =============================================

    /*************************************
    Time Complexity: O(N)
    *************************************/

     /*Print movies rating-wise  based on genre */
    void PrintMoviesRatingWiseBasedOnGenre(string genres)
    {
        MovieNode* Temp=start_movie;
        int count = 0;
        while (Temp != NULL)
        {
            if (strstr(Temp->data.genres.c_str(), genres.c_str()))
                cout << ++count << " ) "
                << "genre : \t" << Temp->data.genres << "\n"
                << "imbd score : \t" << Temp->data.imdb_score << "\n"
                << "movie title : \t" << Temp->data.movie_title << "\n"
                << endl;
            Temp = Temp->next;
        }
    }


    };




/***************************
here goes our main code for testing
****************************/
int main()
{
cout << "#########################################################################################################\n\n"
    "\t\t\tWELCOME TO PRE_MID_TERM_MINI_PROJECT\n\n"
    "##########################################################################################################\n\n";

MovieList* obj1 = new MovieList();
obj1->parserFunction();
//-------------------------------------------------------------------------------------
//obj1->print_Movie_list();
// obj1->print_Actor_List();
// obj1->print_Director_List();
// obj1->print_year_list();


    cout << "Our Project Contins Following Functions !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n";
    cout << "================================== ACTOR FUNCTIONS =====================================\n";
    cout << "1.Search profile of an actor \n"
        "2.Search co-actors of an actor\n"
        "3.Search unique co-actors and print them.\n"
        "4.Print a list of all co-actors of the co-actors of an actor.\n"
        "5.Checks whether A and B are co-actors or not? \n"
        "================================== DIRECTOR FUNCTIONS=====================================\n"
        "6.Prints all movies a director has directed.\n"
        "7.Print directors who have directed movies of a certain genre\n"
        "================================== MOVIE FUNCTIONS========================================\n"
        "8.Search a movie\n"
        "9.Search movies released in a given year\n"
        "10.Print movies year-wise\n"
        "11.Search movies based on genre\n"
        "12.Print movies rating-wise\n"
        "13.Print movies of a certain genre rating-wise\n\n\n";


    cout << "\n=========================== Actor Function # 1 =============================================\n\n";
    cout << "----------------------------  SEARCHING ACTORS PROFILE chronologicalLY ------------------------------\n\n";
    string Actor;
    cout << "Enter Actor name: " << endl;
    getline(cin, Actor);
       
    obj1->SearchActorProfile(Actor);

    cout << "\n\n=========================== Actor Function # 2 =============================================\n\n";
    cout << "---------------------------- Search co-actors of an actor ------------------------------\n\n";
    string actor;
    cout << "Enter Actor name: " << endl;
    getline(cin, actor);
       
    obj1->SearchCoActor(actor);

    cout << "\n\n=========================== Actor Function # 3 =============================================\n\n";
    cout << "---------------------------- Search co-actors of an actor ------------------------------\n\n";
    string actor1;
    cout << "Enter Actor name: " << endl;
    getline(cin, actor1);
  
    obj1->SearchUniqueCoActor(actor1);

    cout << "\n\n=========================== Actor Function # 4 =============================================\n\n";
    cout << "---------------------------- Search co-actors of an actor ------------------------------\n\n";
    string actor2;
    cout << "Enter Actor name: " << endl;
    getline(cin, actor2);

    obj1->SearchCoActorsOfCoActor(actor2);

    cout << "\n\n=========================== Actor Function # 5 =============================================\n\n";
    cout << "----------------------- Checks whether A and B are co-actors or not? ---------------------------\n\n";
    string Actor1;
    string Actor2;
    cout << "Enter 1st Actor name : " << endl;
    getline(cin, Actor1);

    cout << "Enter 2nd Actor name : " << endl;
    getline(cin, Actor2);

    obj1->print_co_actors_or_not(Actor1, Actor2);



    cout << "\n\n=========================== Director Function # 1 =============================================\n\n";
    cout << "--------------------------------- \" Search director \"  ------------------------------\n\n";
    string director = "Andrew Stanton";
    cout << "Enter director name : \n";
    getline(cin, director);
    obj1->search_director(director);

    cout << "\n\n=========================== Director Function # 2 =============================================\n\n";
    cout << "----------------- \" Print directors who have directed movies of a certain genre \"  -------------\n\n";
    string Genre;
    cout << "Enter Genre : \n";
    getline(cin, Genre);
    obj1->search_director_on_basis_of_genre(Genre);


    cout << "\n\n=========================== Movie Function # 1 =============================================\n\n";
    cout << "----------------------------  SEARCHING movie_title  ------------------------------\n\n";
    string movie_title ;
    cout << "Enter Movie title : \n";
    getline(cin, movie_title);

    obj1->search_by_title(movie_title);

    cout << "\n\n=========================== Movie Function # 2 =============================================\n\n";
    cout << "------------------------ \" Search movies released in a given year \"  ------------------------\n\n";
    unsigned short int year;
    cout << "Enter year : " << endl;
    cin >> year;
    obj1->search_by_year(year);

    cout << "\n\n=========================== Movie Function # 3 =============================================\n\n";
    cout << "------------------------ \" Search movies yearwise \"  ------------------------\n\n";

    obj1->searchMoviesYearWise();


    cout << "\n\n=========================== Movie Function # 4 =============================================\n\n";
    cout << "---------------------------- \" Search movies based on genre \"  ----------------------------\n\n";
    string genre = "Adventure";
    obj1->search_movies_on_basis_of_genres(genre);


    cout << "\n\n=========================== Movie Function # 5 =============================================\n\n";
    cout << "------------------------ \" Print movies rating-wise \"  ------------------------\n\n";

    obj1->PrintMoviesRatingWise();

    cout << "\n\n=========================== Movie Function # 6 =============================================\n\n";
    cout << "---------------------------- \" Print movies of a certain genre rating-wise \"  ----------------------------\n\n";
    string genre1;
    cout << "Enter Genre : \n";
    getline(cin, genre1);
    obj1->PrintMoviesRatingWiseBasedOnGenre(genre1);

}

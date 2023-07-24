/*
 *  CSC A48 - Winter 2023 - Assignment 1 starter
 *
 *  (c) 2020-23 Francisco Estrada
 *  - No part of this code may be reproduced without written authorization
 *
 * This is the file where you will be doing most of your work. The
 * functionality you must provide for part 1 of the assignment is described
 * in the handout. Given in detail in the comments at the head of each
 * function below.
 *
 * Plan your work carefully, review the notes for Unit 3, and work carefully
 * to complete the functions in this file. You can bring
 * questions to your TAs or instructors during office hours. Please
 * remember:
 *
 * - You should not share any part of your solution in any form
 * - You should not post any assignment code on Piazza
 * - You should definitely *help* other understand any ideas and
 *   concepts regarding linked lists that you have already mastered,
 *   but being careful not to give away parts of the solution, or
 *   descriptions of how to implement functions below.
 * - If you are not sure whether you can or can not discuss some
 *   particular aspect of the work to be done, remember it's always
 *   safe to talk with your TAs.
 * - Obtaining external 'help' including being given code by an
 *   external party, or being tutored on how to solve
 *   the assignment constitutes an academic offense.
 *
 * All tasks to be completed by you are clearly labeled with a
 * ***** TO DO ****** comment block, which also gives you details
 * about what you have to implement. Look carefully and make sure
 * you don't miss a thing!
 *
 * NOTE: This file contains no main() function! you can not compile
 * it on its own to create an executable. It's meant to be used
 * together with Part1_driver.c - be sure to read that file carefully
 * to understand how to use the tests there - Any additional tests
 * you want to run on the code below should be added to Part1_driver.c
 *
 * Before you even get starter implementing, please complete the
 * student identification section below, and check that you are aware
 * of the policy on academic honesty and plagiarism.
 */

/* Student identification:
 *
 * Student Name (Mallik, Aashir):
 * Student Number: 1009284196
 * UTORid: mallika9
 * Your instructor's name is: Paco Estrada
 */

/* Academic Integrity Statement:
 *
 * I hereby certify that the work contained in this file is my own, and
 * that I have not received any parts of my solution from other sources
 * including my fellow students, external tutoring services, the internet,
 * or algorithm implementations found online.
 *
 * Sign here with your name: Aashir Mallik
 *
 *
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1024

/* Compound data type declarations */
/***************************************************************************/
/******                         TO DO                               ********/
/****** In the space below, complete the definitions of the compound *******/
/****** data types that will be needed to implement the movie review *******/
/****** linked list. This includes the MovieReview type, and the     *******/
/****** ReviewNode. Details about the contents of these can be       *******/
/****** found in the assignment handout. Read them carefully!        *******/
/******                                                              *******/
/****** AFTER completing the basic linked list, complete the CDT     *******/
/****** required to implement a list for the movie's cast.           *******/
/***************************************************************************/

typedef struct castList_struct
{
    char name[MAX_STR_LEN];
    float salary;
    struct castList_struct *next;
} CastList;

typedef struct movieReview_struct
{
    char movie_title[MAX_STR_LEN];
    char movie_studio[MAX_STR_LEN];
    int year;
    float BO_total;
    int score;
    CastList *cast;
} MovieReview;

typedef struct reviewNode_struct
{
    MovieReview review;
    struct reviewNode_struct *next;
} ReviewNode;

ReviewNode *newMovieReviewNode()
{
    /*
     * This function allocates an empty ReviewNode, and initializes the
     * contents of the MovieReview for this node to reasonable (uninitialized) values.
     * The fields in the MovieReview should be set to:
     *  movie_title=""
     *  movie_studio=""
     *  year = -1
     *  BO_total = -1
     *  score = -1
     *  castList = NULL;
     *
     * The *next pointer for the new node MUST be set to NULL
     *
     * The function must return a pointer to the newly allocated and initialized
     * node. If something goes wrong, the function returns NULL
     */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/

    ReviewNode *new_node = NULL;
    new_node = (ReviewNode *)calloc(1, sizeof(ReviewNode));
    if (new_node == NULL)
    {
        printf("new_node(): Sorry! out of memory!\n");
        return NULL;
    }
    strcpy(&new_node->review.movie_studio[0], "");
    strcpy(&new_node->review.movie_title[0], "");
    new_node->review.year = -1;
    new_node->review.BO_total = -1;
    new_node->review.score = -1;
    new_node->review.cast = NULL;
    new_node->next = NULL;
    return new_node;
}

ReviewNode *findMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, ReviewNode *head)
{
    /*
     * This function searches through the linked list for a review that matches the input query.
     * The movie review must match the title, studio, and year provided in the
     * parameters for this function.
     *
     * If a review matching the query is found, this function returns the address of the node that
     * contains that review.
     *
     * If no such review is found, this function returns NULL
     */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    while (head != NULL)
    {
        if (strcmp(head->review.movie_title, title) == 0 &&
            strcmp(head->review.movie_studio, studio) == 0 &&
            head->review.year == year)
        {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

ReviewNode *insertMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, float BO_total, int score, ReviewNode *head)
{
    /*
     * This function inserts a new movie review into the linked list.
     *
     * The function takes as input parameters the data neede to fill-in the review,
     * as well as apointer to the current head of the linked list.
     *
     * If head==NULL, then the list is still empty.
     *
     * The function inserts the new movie review *AT THE HEAD* of the linked list,
     * and returns the pointer to the new head node.
     *
     * The function MUST check that the movie is not already in the list before
     * inserting (there should be no duplicate entries). If a movie with matching
     * title, studio, and year is already in the list, nothing is inserted and the
     * function returns the current list head.
     */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/

        if (findMovieReview(title, studio, year, head) != NULL)
        {
            return head;
        }

    ReviewNode *newReview = newMovieReviewNode();
    if (newReview == NULL)
    {
        printf("Error: memory allocation failed.\n");
        return NULL;
    }

    strcpy(&newReview->review.movie_title[0], title);
    strcpy(&newReview->review.movie_studio[0], studio);
    newReview->review.year = year;
    newReview->review.BO_total = BO_total;
    newReview->review.score = score;
    newReview->next = NULL;

    newReview->next = head;
    return newReview;
}

int countReviews(ReviewNode *head)
{
    /*
     * This function returns the number of reviews.
     */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/

    int counter = 0;
    while (head != NULL)
    {
        counter = counter + 1;
        head = head->next;
    }
    return counter;
}

void updateMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, float BO_total, int score, ReviewNode *head)
{
    /*
     * This function looks for a review matching the input query [title, studio, year].
     * If such a review is found, then the function updates the Box-office total, and the score.
     * If no such review is found, the function prints out
     * "Sorry, no such movie exists in the database"
     */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    int counter = 0;
    while (head != NULL)
    {
        if (findMovieReview(title, studio, year, head) != NULL)
        {
            counter = 1;
            head->review.score = score;
            head->review.BO_total = BO_total;
        }
        head = head->next;
    }

    if (counter == 0)
    {
        printf("Sorry, no such movie exists in the database");
    }
}

ReviewNode *deleteMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, ReviewNode *head)
{
    /*
     * This function removes a review matching the input query from the database. If no such review can
     * be found, it does nothing.
     *
     * The function returns a pointer to the head of the linked list (which may have changed as a result
     * of the deletion process)
     */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    ReviewNode *curr = head;
    ReviewNode *prev = NULL;

    while (curr != NULL)
    {
        if (strcmp(curr->review.movie_title, title) == 0 && strcmp(curr->review.movie_studio, studio) == 0 && curr->review.year == year)
        {
            if (prev == NULL)
            {
                head = curr->next;
            }
            else
            {
                prev->next = curr->next;
            }
            free(curr);
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    return head;
}

float printMovieReviews(ReviewNode *head)
{
    /*
     * This function prints out all the reviews in the database, one after another.
     * Each field in the review is printed in a separate line, with *no additional text*
     * (that means, the only thing printed is the value of the corresponding field).
     *
     * Reviews are separated from each other by a line of
     * "*******************"

     * The function also computes and returns the Box-office total, for all the
     * movies that match the query.
     *
     * See the A1 handout for a sample of the output that should be produced
     * by this function
     */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    float counter;

    if (head == NULL)
    {
        printf("There is nothing in the review list");
    }
    while (head != NULL)
    {
        counter = counter + head->review.BO_total;
        printf("%s\n\n", &head->review.movie_title[0]);
        printf("%s\n\n", &head->review.movie_studio[0]);
        printf("%d\n%f\n%d\n", head->review.year, head->review.BO_total, head->review.score);
        printf("**********************\n");
        head = head->next;
    }
    return counter;
}

float queryReviewsByStudio(char studio[MAX_STR_LEN], ReviewNode *head)
{
    /*
     * This function looks for reviews whose studio matches the input query.
     * It prints out the contents of all reviews matching the query in exactly
     * the same format used by the printMovieReviews() function above.
     *
     * Additionally, it computes and returns the Box-office total, for all the
     * movies that match the query.
     */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/

    float counter;

    if (head == NULL)
    {
        printf("There is nothing in the review list");
    }
    while (head != NULL)
    {
        if (strcmp(head->review.movie_studio, studio) == 0)
        {
            counter = counter + head->review.BO_total;
            printf("%s\n\n", &head->review.movie_title[0]);
            printf("%s\n\n", &head->review.movie_studio[0]);
            printf("%d\n%f\n%d\n", head->review.year, head->review.BO_total, head->review.score);
            printf("**********************\n");
        }
        head = head->next;
    }
    return counter;
}
float queryReviewsByScore(int min_score, ReviewNode *head)
{
    /*
     * This function looks for reviews whose score is greater than, or equal to
     * the input 'min_score'.
     * It prints out the contents of all reviews matching the query in exactly
     * the same format used by the printMovieReviews() function above.
     *
     * Additionally, it computes and returns the Box-office total, for all the
     * movies that match the query.
     */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    float counter;

    if (head == NULL)
    {
        printf("There is nothing in the review list");
    }
    while (head != NULL)
    {
        if (head->review.score >= min_score)
        {
            counter = counter + head->review.BO_total;
            printf("%s\n\n", &head->review.movie_title[0]);
            printf("%s\n\n", &head->review.movie_studio[0]);
            printf("%d\n%f\n%d\n", head->review.year, head->review.BO_total, head->review.score);
            printf("**********************\n");
        }
        head = head->next;
    }
    return counter;
}

ReviewNode *deleteReviewList(ReviewNode *head)
{
    /*
     * This function deletes the movie review database, releasing all the
     * memory allocated to the nodes in the linked list.
     *
     * Returns a NULL pointer so that the head of the list can be set to NULL
     * after deletion.
     */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    ReviewNode *next = NULL;

    while (head != NULL)
    {
        next = head->next;
        free(head);
        head = next;
    }
    return next;
}

/* CRUNCHY SECTION! Do not work on the functions below until
 * your basic linked list is working properly and is fully tested!
 */

ReviewNode *sortReviewsByTitle(ReviewNode *head)
{
    /*
     * This function sorts the list of movie reviews in ascending order of movie
     * title. If duplicate movie titles exist, the order is arbitrary (i.e. you
     * can choose which one goes first).
     *
     * However you implement this function, it must return a pointer to the head
     * node of the sorted list.
     */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    ReviewNode *i, *j, *min;
    MovieReview tmp;

    for (i = head; i != NULL; i = i->next)
    {
        min = i;
        for (j = i->next; j != NULL; j = j->next)
        {
            if (strcmp(j->review.movie_title, min->review.movie_title) < 0)
            {
                min = j;
            }
        }
        if (min != i)
        {
            tmp = i->review;
            i->review = min->review;
            min->review = tmp;
        }
    }

    return head;
}

void insertCastMember(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, ReviewNode *head, char name[MAX_STR_LEN], float salary)
{
    /*
     * This function inserts the name of a cast member for the given movie into the
     * linked list of cast members. The new cast member must go to the end of the list.
     *
     * Duplicate names are allowed - this time!
     *
     * Notice the function receives the title, studio, and year for the movie, as
     * well as a pointer to the movie DB linked list. The function must find the
     * correct movie and if such a movie exists, add the cast member's name to its
     * cast list.
     *
     * If no such movie is found, this function does nothing.
     *
     * You're free to add helper functions to insert the cast member's name
     * into the cast list.
     */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    ReviewNode *current = head;
    while (current != NULL)
    {
        if (findMovieReview(title, studio, year, current) != NULL)
        {
            CastList *new_cast_member = (CastList *)calloc(1, sizeof(CastList));
            strncpy(new_cast_member->name, name, MAX_STR_LEN);
            new_cast_member->salary = salary;
            CastList *prev = NULL;
            CastList *current_cast_member = current->review.cast;
            while (current_cast_member != NULL && current_cast_member->salary > salary)
            {
                prev = current_cast_member;
                current_cast_member = current_cast_member->next;
            }

            if (prev == NULL)
            {
                new_cast_member->next = current_cast_member;
                current->review.cast = new_cast_member;
            }
            else
            {
                prev->next = new_cast_member;
                new_cast_member->next = current_cast_member;
            }

            return;
        }
        current = current->next;
    }
}

void printNames(ReviewNode *movie)
{
    // Prints out names of cast members for this movie
    CastList *p;
    if (movie == NULL || movie->review.cast == NULL)
        return;
    p = movie->review.cast;
    printf("The cast for this movie are:\n");
    while (p != NULL)
    {
        printf("Cast Member: %s, Salary: %f\n", p->name, p->salary);
        p = p->next;
    }
}
void whosTheStar(ReviewNode *head)
{
    CastList *stars = NULL;
    CastList *star;      
    int num_movies;               
    float total_earnings;          
    float avg_earnings;            
    CastList *best_star = NULL;    
    float best_avg_earnings = 0.0; 

    ReviewNode *node = head;
    while (node != NULL)
    {
        CastList *cast = node->review.cast;
        while (cast != NULL)
        {
            star = stars;
            while (star != NULL && strcmp(star->name, cast->name) != 0)
            {
                star = star->next;
            }
            if (star == NULL)
            {
                star = (CastList *)malloc(sizeof(CastList));
                strncpy(star->name, cast->name, MAX_STR_LEN - 1);
                star->salary = cast->salary;
                star->next = stars;
                stars = star;
            }
            else
            {
                star->salary += cast->salary;
            }
            cast = cast->next;
        }
        node = node->next;
    }

    star = stars;
    while (star != NULL)
    {
        num_movies = 0;
        total_earnings = 0.0;
        node = head;
        while (node != NULL)
        {
            CastList *cast = node->review.cast;
            while (cast != NULL)
            {
                if (strcmp(cast->name, star->name) == 0)
                {
                    total_earnings += node->review.BO_total - cast->salary;
                    num_movies++;
                    break;
                }
                cast = cast->next;
            }
            node = node->next;
        }
        if (num_movies > 0)
        {
            avg_earnings = total_earnings / num_movies;
            if (avg_earnings > best_avg_earnings)
            {
                best_avg_earnings = avg_earnings;
                best_star = star;
            }
        }
        star = star->next;
    }

    if (best_star != NULL)
    {
        printf("%s\n%.2f\n", best_star->name, best_avg_earnings);
    }
}

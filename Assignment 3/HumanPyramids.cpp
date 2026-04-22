#include "HumanPyramids.h"
#include "error.h""
#include "grid.h"
using namespace std;

/* TODO: Refer to HumanPyramids.h for more information about what this function should do.
 * Then, delete this comment.
 */
/*   未使用记忆器版本
double weightOnBackOf(int row, int col, int pyramidHeight) {
    if(row<0 || col<0 || row<col || row >=  pyramidHeight)
        error("invaild position");
    if(row ==0 && col ==0)  return 0;
    else{
        if(col==0)
            return (weightOnBackOf(row-1,col,pyramidHeight)/2+80);
        if(row==col)
            return (weightOnBackOf(row-1,col-1,pyramidHeight)/2+80);
        else
        return (weightOnBackOf(row-1,col-1,pyramidHeight)/2+80)+(weightOnBackOf(row-1,col,pyramidHeight)/2+80);
    }
}
*/

double help(int row, int col, int pyramidHeight,Grid<double>&map){  //必须使用引用传递，值传递每次调用都需要复制
    if(row<0 || col<0 || row<col || row >=  pyramidHeight)
        error("invaild position");
    if(row ==0 && col ==0)  {
        map[row][col]=0;
        return 0;
    }
    if (map[row][col]!=-1) return map[row][col];
    else {
        double result;
        if(col==0)
            result= (help(row-1,col,pyramidHeight,map)/2+80);

        else if(row==col)
            result =(help(row-1,col-1,pyramidHeight,map)/2+80);
        else
            result=(help(row-1,col-1,pyramidHeight,map)/2+80)+(help(row-1,col,pyramidHeight,map)/2+80);
        map[row][col]=result;
        return result;
    }
}

//使用记忆器版本
double weightOnBackOf(int row, int col, int pyramidHeight) {
    Grid<double> map (pyramidHeight,pyramidHeight,-1);  //-1初始化grid
    return help(row,col,pyramidHeight,map);
}




/* * * * * * Test Cases * * * * * */
#include "GUI/SimpleTest.h"

/* TODO: Add your own tests here. You know the drill - look for edge cases, think about
 * very small and very large cases, etc.
 */














/* * * * * * Test cases from the starter files below this point. * * * * * */

PROVIDED_TEST("Check Person E from the handout.") {
    /* Person E is located at row 2, column 1. */
    EXPECT_EQUAL(weightOnBackOf(2, 1, 5), 240);
}

PROVIDED_TEST("Function reports errors in invalid cases.") {
    EXPECT_ERROR(weightOnBackOf(-1, 0, 10));
    EXPECT_ERROR(weightOnBackOf(10, 10, 5));
    EXPECT_ERROR(weightOnBackOf(-1, 10, 20));
}

PROVIDED_TEST("Stress test: Memoization is implemented (should take under a second)") {
    /* TODO: Yes, we are asking you to make a change to this test case! Delete the
     * line immediately after this one - the one that starts with SHOW_ERROR - once
     * you have implemented memoization to test whether it works correctly.
     */
    /* Do not delete anything below this point. :-) */

    /* This will take a LONG time to complete if memoization isn't implemented.
     * We're talking "heat death of the universe" amounts of time. :-)
     *
     * If you did implement memoization but this test case is still hanging, make
     * sure that in your recursive function (not the wrapper) that your recursive
     * calls are to your new recursive function and not back to the wrapper. If you
     * call the wrapper again, you'll get a fresh new memoization table rather than
     * preserving the one you're building up in your recursive exploration, and the
     * effect will be as if you hadn't implemented memoization at all.
     */
    EXPECT(weightOnBackOf(100, 50, 200) >= 10000);
}

/* TODO: Add your own tests here. You know the drill - look for edge cases, think about
 * very small and very large cases, etc.
 */

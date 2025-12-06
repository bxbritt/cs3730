int x4[100];
int f ( int z)
  begin

   write "inside f";
    write z;
     return z;
  end

void main(void) begin
   int g;
   int user;
   boolean a, b, c;
   int iteration;
   
    g=f(2);
    write g;
    write "\n";
    write "Pick a number: ";
    read user;
    write "Wow! ";
    write user;
    write " is my fav number!";
    write "\n";

    //boolean test
   
    a = true;
    b = false;

    write a;
    write "\n";
    write b;
    write "\n";


    // NOT
    c = not a;      // should become false
    write c;
    write "\n";

    c = not b;      // should become true
    write c;
    write "\n";

    //AND && OR
    c = a and b;    // false
    write c;
    write "\n";

    c = a or b;     // true
    write c;
    write "\n";

    //if test

    if(a)
    then write "A is true";
    endif
    
//while test
    write "\n";
    write "while loop test";
    write "\n";
    write "starting with number...";
    iteration = 5;
    write iteration;
    write "\n";

    while(iteration > 0) do
    begin
     write iteration;
    iteration = iteration - 1;
    write "\n";
    end

   
end

# Sudoku

<p>This a program to allow the user to play Sudoku. For details on the rules of the game, see:http://en.wikipedia.org/wiki/Sudoku</p>

<p>The program will prompt the user for the filename of the game he or she is currently working on and display the board on the screen. The user will then be allowed to interact with the game by selecting which square he or she wishes to change. While the program will not solve the game for the user, it will ensure that the user has not selected an invalid number. If the user types 'S' in the prompt, then the program will show the user the possible valid numbers for a given square. When the user is finished, then the program will save the board to a given filename and exit.</p>
<h2>Interface Design</h2>
<ol>
  <li>A saved game is stored as myGame.txt:</li>
  <pre>
    7 2 3 0 0 0 1 5 9
    6 0 0 3 0 2 0 0 8
    8 0 0 0 1 0 0 0 2
    0 7 0 6 5 4 0 2 0
    0 0 4 2 0 7 3 0 0
    0 5 0 9 3 1 0 4 0
    5 0 0 0 7 0 0 0 3
    4 0 0 1 0 3 0 0 6
    9 3 2 0 0 0 7 1 4
  </pre>
  <ul>
    <li>Note that '0' corresponds to an unknown value. </li>
  </ul>
  <p></br>The following is an example run of the program.</p>
</ol>
 
<h2>Program starts</h2>
    <ul>
      <li>Where is your board located? myGame.txt</li>
      <li>With the filename specified, the program will display a menu of options:
  Options:</li>
        <ul>
          <li>?  Show these instructions</li>
          <li>D  Display the board</li>
          <li>E  Edit one square</li>
          <li>S  Show the possible values for a square</li>
          <li>Q  Save and quit</li>
        </ul>
      <li>After this, the board as read from the file will be displayed:</li>
       <pre>  
                  A B C D E F G H I
                1  7 2 3|     |1 5 9
                2  6    |3   2|    8
                3  8    |  1  |    2
                   -----+-----+-----
                4    7  |6 5 4|  2  
                5      4|2   7|3  
                6    5  |9 3 1|  4 
                    -----+-----+-----
                7  5    |  7  |    3
                8  4    |1   3|    6
                9  9 3 2|     |7 1 4
       </pre>
      </ul>
      <ul>
        <li>Here, the user will be prompted for a command (the main prompt).</li>
        <li>Please note that you will need a newline, a carat ('>'), and a space before the prompt.</li>
        <li>The next action of the program will depend on the user's command. If the user types an invalid command, then the following message will be displayed:</li>
        ERROR: Invalid command
       </ul>
   
<h2>Show Instructions</h2>
        <p>If the user types '?', then the menu of options will be displayed again. These are the same instructions that are displayed when the program is first run.</p>
        
<h2>Display the Board</h2>
        <p>If the user types 'D', then the board will be redrawn. This is the same as the drawing of the board when the program is first run.</p>    
<h2>Save and Quit</h2>
        <p>If the user types 'Q', then he or she will be prompted for the filename:</p>
        <ul>
          <li>What file would you like to write your board to: newGame.txt</li>
          <li>The program will display the following message:</br>
              Board written successfully</li>
          <li>Then the program will terminate.</li>
        </ul>
    <h2>Edit One Square</h2>
        <p>If the user types 'E', then the program will prompt him for the coordinates and the value for the square to be edited:</p>
        <ul>
          <li>What are the coordinates of the square: A1</li>
          <p>If the value is invalid or if the square is already filled, then the program will display one of the following message and return to the main prompt:</p>
          <li>ERROR: Square 'zz' is invalid</li>
          <li>ERROR: Square 'A1' is filled</li>
        </ul>
        <p></br>With a valid coordinate, then the program next prompts the user for the value:</p>
        </ul>
          <li>What is the value at 'A1': 9</li>
        </ul>
       <p>If the user types a value that is outside the accepted range (1 ≤ value ≤ 9) or does not follow the rules of Sudoku, then a message appears and the program returns to the main prompt:</p>
       <ul>
        <li>ERROR: Value '9' in square 'A1' is invalid</li>
       </ul>
 <h2>Show Possible Values</h2>
    <p>If the user types 'S', then the program will prompt him for the coordinates and display the possible values:</p>
    <ul>
      <li>What are the coordinates of the square: A1</li>
    </ul>
    <p>The same parsing logic applies here as for the Edit One Square case. Once the user has selected a valid coordinate, then the program will display the possible values:</p>
    <ul>
      <li>The possible values for 'A1' are: 1, 5, 8, 9</li>
    </ul>
    <p>After the message appears, the program returns to the main prompt.</p>
</ol>

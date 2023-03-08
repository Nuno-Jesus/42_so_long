# **so_long**
This project was graded <strong>125/100</strong>.

## 📒 **About**
This project is one of the 3 possible graphical projects to develop in Rank 02. You'll learn about rendering, sprites, animations, color schemes and game development in 2D. One of the coolest projects in my opinion!

## **Mandatory Part**

<p align=center>

|![mandatory](https://user-images.githubusercontent.com/93390807/223617088-f065df7b-ee8b-41c9-bc0e-45d7027cdad1.gif)|
|:--:|
|Level 3|

</p>

### **Entities**

<p align=center>

|![player](https://user-images.githubusercontent.com/93390807/223616745-00fa689c-6503-4be7-a7b9-6152fcaf4219.png)|![coin](https://user-images.githubusercontent.com/93390807/223617101-57d53f5f-1b76-43f2-96c3-6b4c8b4c990f.png)|![space](https://user-images.githubusercontent.com/93390807/223616742-34534528-4a9a-4171-aeb7-859d1f0182ed.png)|![wall](https://user-images.githubusercontent.com/93390807/223616739-74a3ff81-a58e-4899-9d7d-d2e309c6cec6.png)|![exit](https://user-images.githubusercontent.com/93390807/223616748-2a04ada7-cb8c-4c94-8f32-876ec1539984.png)|
|:--:|:--:|:--:|:--:|:--:|
|Player|Collectable|Empty|Wall|Exit|

</p>


## **Bonus Part**

<p align=center>

|![bonus](https://user-images.githubusercontent.com/93390807/223605965-6dd26c72-4f38-4c80-b294-af8a2cb54dd8.gif)|
|:--:|
|Level 3|

</p>

### **Entities**

<p align=center>

|![player](https://user-images.githubusercontent.com/93390807/223611394-8fca35c8-00d7-4501-813b-aa500fb8d060.gif)|![potion](https://user-images.githubusercontent.com/93390807/223611395-5375f42b-6ad4-4caf-96bc-f1b174734abf.gif)|![enemy](https://user-images.githubusercontent.com/93390807/223611386-9d5ac4e9-6e33-4965-ad02-31e117ef1620.gif)|![enemy2](https://user-images.githubusercontent.com/93390807/223611391-4d6759f8-c101-4689-b22c-4e4f9dd446d0.gif)|![exit](https://user-images.githubusercontent.com/93390807/223611577-b72649c6-239a-4aa7-9282-ad0dba45bbc3.png)|
|:--:|:--:|:--:|:--:|:--:|
|Player|Collectable|Enemy|Enemy Stage 2|Exit|

</p>

### **Extra features**
- Different xpm images for inner and outter walls, depending on the surrounding walls (not covering all cases yet)
- Enemies start by moving randomly. After collecting every potion, the enemies become angry, turning blue. At this point, they double their moving speed and start chasing the player.
- More to come...

## 🚨 **Disclaimer**
At 42, the C projects are built following a bunch of rules that enforce good coding style. Some of them are:

	- No for, do while, switch, case or goto are allowed
	- No more than 25 lines per function and 5 functions per file
	- No assigns and declarations in the same line (unless static)
	- No more than 5 variables in 1 function
	... 

## 🔧 **Implementation**

<table align=center>
	<thead>
		<tr>
			<th>Part</th>
			<th>File Name</th>
			<th>Functionality</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td rowspan = 8><strong>Mandatory</strong></td>
			<td>get_next_line/</td>
			<td>Contains the files from the get_next_line project</td>
		</tr>
		<tr>
			<td>includes/</td>
			<td>Contains all the necessary .h files</td>
		</tr>
		<tr>
			<td>libft/</td>
			<td>Contains the files from the libft project</td>
		</tr>
		<tr>
			<td>maps/</td>
			<td>Contains the map files used to test the project</td>
		</tr>
		<tr>
			<td>mlx/</td>
			<td>Contains the files of the graphics library to render stuff</td>
		</tr>
		<tr>
			<td>srcs/</td>
			<td>Contains the files strictly created for this projects (documented in the .h files)</td>
		</tr>
		<tr>
			<td>xpm/</td>
			<td>Contains the xpm version of the images used to render the game</td>
		</tr>
		<tr>
			<td>main.c</td>
			<td>Where the project is launched from</td>
		</tr>
		<tr>
			<td rowspan = 5><strong>Bonus</strong></td>
			<td>map/</td>
			<td>Responsible for reading, parsing and assembling the map</td>
		</tr>
		<tr>
			<td>move/</td>
			<td>Has the logic to move both player and enemies. It also contains the enemies strategies.</td>
		</tr>
		<tr>
			<td>render/</td>
			<td>Files that handle the rendering process, including animations and choosing the walls images</td>
		</tr>
		<tr>
			<td>utils/</td>
			<td>Generic and debugging functions</td>
		</tr>
		<tr>
			<td>init.c</td>
			<td>Contains the starting loop function and allocates all necessary memory for the program to work.</td>
		</tr>
	</tbody>
</table>


## 📦 **Compilation**
To compile so_long you should run `make` in the terminal.

This rule will generate a `so_long` file, which is the zipped version of all the object files. To launch the executable you should follow this syntax...

```sh
$ ./so_long path_to_the_map_file.ber
```

...where the second argument is the file you should use as input to display the map. Notice that any misconfiguration in the map file won't launch the graphical environment.

If you want to run the bonus, just run `make bonus` and then, hit the terminal with the following command:

```sh
$ ./so_long_bonus path_to_the_map_file.ber
```

> There are bonus dedicated maps in the maps/bonus folder

## 💫 **Testing**

This project was tested using self-created map files to test extreme cases.


## 📞 **Contact me**

Feel free to ask me any questions through Slack (**ncarvalh**).


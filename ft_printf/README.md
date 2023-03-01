# **ft_printf**
This project was graded <strong>110/100</strong>.


## 📒 **About**
You know the rules: if a function is not allowed, you can't use it. It sucks right? Well, this is your chance to implement printf()! You'll be able to use it in the following projects, alongside with the other functions you developed so far.

## 🚨 **Disclaimer**
At 42, the C projects are built following a bunch of rules that enforce good coding style. Some of them are:

	- No for, do while, switch, case or goto are allowed
	- No more than 25 lines per function and 5 functions per file
	- No assigns and declarations in the same line (unless static)
	- No more than 5 variables in 1 function
	... 

## 🔧 **Implementation**
> Unfortunately I implemented the bonus in the same files as the mandatory, so everything will be mixed up

<table>
	<thead>
		<tr>
			<th>Part</th>
			<th>File Name</th>
			<th>Functionality</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td rowspan = 11><strong>Mandatory</strong></td>
			<td>libft/</td>
			<td>Contains the files from the libft project</td>
		</tr>
		<tr>
			<td>ft_convert_char.c</td>
			<td>Contains the functions to handle the %c conversion</td>
		</tr>
		<tr>
			<td>ft_convert_hexa.c</td>
			<td>Contains the functions to handle the %x and %X conversions</td>
		</tr>
		<tr>
			<td>ft_convert_integer.c</td>
			<td>Contains the functions to handle the %d and %i conversions</td>
		</tr>
		<tr>
			<td>ft_convert_module.c</td>
			<td>Contains the functions to handle the %% conversion</td>
		</tr>
		<tr>
			<td>ft_convert_pointer.c</td>
			<td>Contains the functions to handle the %p conversion</td>
		</tr>
		<tr>
			<td>ft_convert_string.c</td>
			<td>Contains the functions to handle the %s conversion</td>
		</tr>
		<tr>
			<td>ft_convert_unsigned.c</td>
			<td>Contains the functions to handle the %u conversion</td>
		</tr>
		<tr>
			<td>ft_printf_utils.c</td>
			<td>Contains the utilitary functions developed specifically for this project</td>
		</tr>
		<tr>
			<td>ft_printf.c</td>
			<td>Contains the ft-printf function (main loop) and a function to redirect conversions</td>
		</tr>
		<tr>
			<td>ft_printf.h</td>
			<td>Contains the prototypes of every function specifically developed for this project</td>
		</tr>
		<tr>
			<td rowspan = 1><strong>Bonus</strong></td>
			<td>ft_flags.c</td>
			<td>Contains functions to handle modifiers (only '#', ' ' and '+')</td>
		</tr>
	</tbody>
</table>


## 📦 **Compilation**
To compile the library you can either run `make` or `make bonus` in the terminal. Both `make` and `make bonus` will compile and link all files together.

Both rules generate a `libftprintf.a` file, which is zipped version of all the object files. Imagine you have a `main.c` file and you want to use your library in it. You can compile it by running the following command:

```sh
$ cc -Wall -Wextra -Werror main.c -lftprintf -L _path_to_this_folder_/libftprinf.a -I _path_to_this_folder_/ft_printf.h
```

Dont forget to include the `.h` files!

## 💫 **Testing**

This project was tested using the [printfTester](https://github.com/Tripouille/printfTester) and manual revision only.


## 📞 **Contact me**

Feel free to ask me any questions through Slack (**ncarvalh**).


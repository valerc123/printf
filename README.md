# Function _printf() in C
This function sends formatted output to stdout.
```bash
int _printf(const char* format, ...);
```

## Usage
**format** − This is the string that contains the text to be written to stdout. It can optionally contain embedded format tags that are replaced by the values specified in subsequent additional arguments and formatted as requested. Format tags prototype is %[format]

## Format specifier
| Format | Description |
| ------ | ------ |
|%i| got replaced by value an integer variable |
|%d| got replaced by value an integer variable decimal base 10 |
|%c| got replaced by value of a character variable |
|%s| got replaced by value of a pointer char variable|
|%%| got replaced by a single '%'. |


 %i - Example:
```python
int age = 10; 

printf("She is %i years old.", age);
```
>output:
```python
she is 10 year old.
```

%d - Example:
```python
int average = 1500;

 _printf("The average is: %d.", average);
```
>output:
```python
The average is: 1500.
```

%c - Example:
```python
char answer = 'a'; 

_printf("The right answer is: %c.", answer);
```
>output:
```python
The right answer is: a.
```

%s - Example:
```python
char *name = "Valentina";
char *lastname = "Rua";

_printf("My name is %s %s.", name, lastname);
```
>output:
```python
My name is Valentina Rua.
```

%% - Example:
```python
int percent = 100;

_printf("The profits were %i%%.", percent);
```
>output:
```python
The profits were 100%.
```


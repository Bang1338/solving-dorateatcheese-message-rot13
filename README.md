<h1 align="center">
Solving Dorateatcheese's message (ROT13)
</h1>

<p align="center"> 
  <kbd>
<img src="https://media.discordapp.net/attachments/948882537554518019/1065127498611970129/image.png">
  </kbd>
</p>

<h3 align="center">
Me when i don't know that this is ROT13, but this will be helpful if you're trying to cracking ROT13 :)
</h3>

## Story
2 days ago I just smashing my keyboard, but suddenly my friend Dorateatcheese, sending weird message.

<p align="left"> 
  <kbd>
<img src="https://media.discordapp.net/attachments/910881423471312896/1065129643251871836/image.png">
  </kbd>
</p>

No one know what he saying.

Until Jan 18th 2023, Dorateatcheese said in Zalo: `You will never decode my message`, this challenge me.

<p align="left"> 
  <kbd>
<img src="https://cdn.discordapp.com/attachments/910881423471312896/1065130636496609300/e1c65a48ed5a36046f4b.jpg">
  </kbd>
</p>

I tried [CyberChef](https://gchq.github.io/CyberChef), but... doesn't detect anything.

## How I decoded it
`To find it, we need to know the magic.`
I'll take `Uryyb thlf jung'f hc?` as example.
* First, find the magic. I found the word `jung'f` look familiar to `that's` or `what's`
* Second, see the range of each word in [ASCII Table](https://www.rapidtables.com/code/text/ascii-table.html).
I take the range of `j` with `t` and `w`

```
| j | 106 + 10 = 116  | t |
| j | 106 + 13 = 119  | w |
```

Next, take the range of `u` with `h`

```
| u | 117 - 13 = 104  | h |
```

And continue, we have:

```
| j | 106 + 13 = 119  | w |
| u | 117 - 13 = 104  | h |
| n | 110 - 13 =  97  | a |
| g | 103 + 13 = 110  | t |
| ' | N O T   U S E D | ' | if this is space or not a char, don't.
| f | 102 + 13 = 115  | s |
```

This have a lot of number `13` (i hate that number), so the offset is `+13` and `-13`
* Third, I try with other character, however...
* 
If we take `z` for example, the ASCII code is `122`, if we using `+13` this will go to other one.

<p align="left"> 
  <kbd>
<img src="https://user-images.githubusercontent.com/75790567/213096815-68a8a29d-5b22-4283-a0f9-073f736c43bc.png">
  </kbd>
</p>

So, we have to use `-13` instead.
* Note: If UPPERCASE CHAR, the range must be `65 (A)` to `90 (Z)`. if lowercase char, the range must be `97 (a)` to `122 (z)`. Or else it won't be working.
I fully solved in Notepad (i wanted to do it on Excel, but lazy).

<p align="left"> 
  <kbd>
<img src="https://user-images.githubusercontent.com/75790567/213097537-1361c222-daa9-426d-b603-151b6fb998da.png">
  </kbd>
</p>

Later I coded C++ code to solve the Dorateatcheese puzzle. You can check it.

## Process making C++ code
Since i'm too lazy to do it by hand, I've to do it in C++

```cpp
// offset is int.
if(s[i] >= 'a' && s[i] <='z' || s[i] >= 'A' && s[i] <='Z'){
    if(s[i] + offset >= 'a' && s[i] + offset <='z' || s[i] + offset >= 'A' && s[i] + offset <='Z')
        cout<<char(s[i] + offset);
    else if (s[i] - offset >= 'a' && s[i] - offset <='z' || s[i] - offset >= 'A' && s[i] - offset <='Z')
        cout<<char(s[i] - offset);
}
```

However, when I run it, this will fail on second rule: 
* If UPPERCASE CHAR, the range must be `65 (A)` to `90 (Z)`. if lowercase char, the range must be `97 (a)` to `122 (z)`. Or else it won't be working.
So, I recode it.

```cpp
for(int i=0; i<=s.size(); i++){
        if(s[i] >= 'a' && s[i] <='z'){
            if(s[i] + offset >= 'a' && s[i] + offset <='z')
                cout<<char(s[i] + offset);
            else if (s[i] - offset >= 'a' && s[i] - offset <='z')
                cout<<char(s[i] - offset);
        }
        else if (s[i] >= 'A' && s[i] <='Z'){
            if(s[i] + offset >= 'A' && s[i] + offset <='Z')
                cout<<char(s[i] + offset);
            else if (s[i] - offset >= 'A' && s[i] - offset <='Z')
                cout<<char(s[i] - offset);
        }
        else if (s[i] == ' ') cout<<" ";
        else cout<<s[i];
    }
```
What this thing do?
```cpp
if(s[i] >= 'a' && s[i] <='z'){

}
else if (s[i] >= 'A' && s[i] <='Z'){

}
```
* If the current `i` is valid lowercase char or UPPERCASE CHAR, we do something.

```cpp
if(s[i] + offset >= 'a' && s[i] + offset <='z')
        cout<<char(s[i] + offset);
else if (s[i] - offset >= 'a' && s[i] - offset <='z')
        cout<<char(s[i] - offset);
```
* This is for lowercase char
* If we take current character __plus__ the number (offset) we shift is valid char, we print out.
* Else if we take current character __minus__ the number (offset) we shift is valid char, we print out.

```cpp
if(s[i] + offset >= 'a' && s[i] + offset <='z')
        cout<<char(s[i] + offset);
else if (s[i] - offset >= 'a' && s[i] - offset <='z')
        cout<<char(s[i] - offset);
```
* Same thing as lowercase char, but this is for UPPERCASE CHAR

```cpp
else if (s[i] == ' ') cout<<" ";
else cout<<s[i];
```
* If it have space ` `, we print ` `
* Else we print something else (like `@`)

## The end...?
* After done a while, I already have [nightmare on number 13](https://en.wikipedia.org/wiki/Triskaidekaphobia).
* When I played CyberChef a while, I found out ROT13. I was thinking: `oh man not number 13...`, I drag it and...
<p align="left"> 
  <kbd>
<img src="https://user-images.githubusercontent.com/75790567/213098317-e80915f0-23ce-44b8-83b0-0acaa211600a.png">
  </kbd>
</p>

* So, that entire time, Dorateatcheese USING ROT13?????
* Oh well, this is worth a try.

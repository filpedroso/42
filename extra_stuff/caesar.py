def caesar_cipher(cripto, key):
    message = ""
    for c in cripto:
        if c.isalpha():  # Only shift alphabetic characters
            # Determine the ASCII offset based on whether the character is upper or lower case
            offset = 65 if c.isupper() else 97
            # Perform the shift
            shifted = (ord(c) - offset + key) % 26 + offset
            # Append the new character to the message
            message += chr(shifted)
        else:
            # If it's not an alphabetic character, leave it unchanged
            message += c
    return message

# Example usage:
cripto = """Rnpu cebwrpg bs gur 97 Pbzzba Pber pbagnvaf na rapbqrq uvag. Sbe
rnpu pvepyr, bayl bar cebwrpg cebivqrf gur pbeerpg uvag arrqrq sbe
gur arkg pvepyr. Guvf punyyratr vf vaqvivqhny, gurer vf bayl n
cevmr sbe bar fghqrag jvaare cebivqvat nyy qrpbqrq zrffntrf. Nal
nqinagntrq crbcyr pna cynl, yvxr pheerag be sbezre fgnss, ohg gur
cevmr jvyy erznva flzobyvp. Gur uvag sbe guvf svefg cebwrpg vf:
Ynetr pbjf trarebfvgl pbzrf jvgu punegf naq sbhe oybaqr ungf gb qrsl
hccre tenivgl ureb"""
key = 13
encrypted_message = caesar_cipher(cripto, key)
print(encrypted_message)  # Outputs: "Khoor, Zruog!"

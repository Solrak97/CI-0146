import re

str=["js/prettify-full.en.js 4e6ee9163220","js/moderator.en.js:", "transaction no: 75553942;", "", "transaction no: 75551263;", "transaction no: 46553942;", "c01c47765ca21b82b08b90403b4c7af3886098683e3869ad1:", "transaction no: 75554942;"]

#Type your answer here.

regex = r'(.+);$'
lst = re.findall(regex, str)



print(lst)

const arr = [1,2,3,1,2,3,1,2,3];
let c=0;
for (let i = 0; i < arr.length; i++) {
  if(arr[i]===1)
    c++;
}
console.log(c)

const ar=['A','E','W','Q','A'];
let d=0;
for (let i = 0; i < ar.length; i++) {
  if(ar[i]==='A'){
    d = 1;
    break;
  }
}
if(d===0)
  console.log('X');
else
  console.log('O');


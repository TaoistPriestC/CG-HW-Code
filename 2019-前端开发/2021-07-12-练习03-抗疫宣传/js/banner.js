window.onload = function(){
    let lt = document.getElementById("lt-button");
    let rt = document.getElementById("rt-button");
    let idx = 0;
    let imgs = document.getElementById("ul1").children;
    let button = document.getElementById("ul2").children;
    lt.onclick = function () {
        // console.log("受到点击");//用于调试
        idx = (idx - 1 + imgs.length) % imgs.length;
        for(let i = 0; i < imgs.length; i++){
            imgs[i].style.cssText="z-index:0;";
            button[i].style.cssText="background-color:#fff;color:rgb(0,140,255);";
        }
        imgs[idx].style.cssText="z-index:100;";
        button[idx].style.cssText="background-color:rgb(0,140,255);color:#fff;"; 
    }
    rt.onclick = function () {
        // console.log("受到点击");//用于调试
        idx = (idx + 1 + imgs.length) % imgs.length;
        for(let i = 0; i < imgs.length; i++){
            imgs[i].style.cssText="z-index:0;";
            button[i].style.cssText="background-color:#fff;color:rgb(0,140,255);";
        }
        imgs[idx].style.cssText="z-index:100;";
        button[idx].style.cssText="background-color:rgb(0,140,255);color:#fff;"; 
    }
}
window.onload=function(){
	var flag = true;
	$(".header-top-third-ul").click(function(){
		if(flag==true){
			$(".header-top-third-ul > li").css("border","1px solid #008cff");
			$(".header-top-fourth").stop(true,true).slideDown(100);
		}else{
			$(".header-top-third-ul > li").css("border","1px solid #8A8A8A");
			$(".header-top-fourth").stop(true,true).slideUp(100);
        }
        flag = !flag;
	});
}
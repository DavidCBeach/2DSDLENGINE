#version 130
//The fragment shader operates on each pixel in a given polygon

in vec2 fragmentPosition;
in vec4 fragmentColor;
in vec2 fragmentUV;
//This is the 3 component float vector that gets outputted to the screen
//for each pixel.
out vec4 color;


uniform float time;
uniform sampler2D mySampler;
void main() {
	vec4 textureColor = texture(mySampler, fragmentUV );
	color = fragmentColor * textureColor;
	time;
	//color = textureColor * vec4(fragmentColor.r *(cos(fragmentPosition.x + time)+3.0)*0.5,
//fragmentColor.g *(cos(fragmentPosition.y + time)+3.0)*0.5,
//fragmentColor.b *(cos(fragmentPosition.x*0.3 + time)+3.0)*0.5,
//fragmentColor.a );;
    //cos(x) returns a number between -1 and 1. To convert it into the range 0 to 1
    //you simply do (cos(x) + 1.0) * 0.5

	
    //Make crazy colors using time and position!
    //color = fragmentColor + vec4(1.0 *(cos(time)+1.0)*0.5,1.0 *(cos(time)+1.0)*0.5,1.0 *(sin(time)+1.0)*0.5,0.0);
	//color = vec4(fragmentColor.r *(cos(fragmentPosition.x + time)+1.0)*0.5,
//fragmentColor.g *(cos(fragmentPosition.y + time)+3.0)*0.5,
//fragmentColor.b *(cos(fragmentPosition.x*0.3 + time)+1.0)*0.5,
//fragmentColor.a );

}
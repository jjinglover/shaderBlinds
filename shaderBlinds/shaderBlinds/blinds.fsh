#version 330 core

uniform sampler2D texture0;					
uniform sampler2D texture1;											
uniform float unitWidth;	
//窗页宽度 范围0-1				
uniform float offset;						
//显示窗页的编译系数 范围0-1
in vec4 FragColor;                
in vec2 TexCoord;                    
 
out vec4 color;

void main()														
{																		
     float modPixel = mod(TexCoord[0], unitWidth);				
     float showPixel = offset* unitWidth;					
     if (modPixel < showPixel)			 						
     {														
          color = FragColor * texture2D(texture1, TexCoord);			
     }															
     else														
     {															
          color = FragColor * texture2D(texture0, TexCoord);			
     }													
}
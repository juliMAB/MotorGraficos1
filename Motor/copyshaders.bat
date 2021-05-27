cd %2\Game\res
mkdir Shaders
cd Shaders
copy "%1\Shaders\fragment.shader" "%2\Game\res\Shaders" /Y
copy "%1\Shaders\vertex.shader" "%2\Game\res\Shaders" /Y
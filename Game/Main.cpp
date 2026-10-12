#include "Engine.h"
#include "Core/File.h"
#include "Renderer/Shader.h"
#include "Renderer/VertexBuffer.h"
#include "Renderer/Pipeline.h"

#include "Resources/ResourceManager.h"


using namespace nu;

//class Object
//{
//public:
//    Object() { std::cout << "constructor\n"; }
//    ~Object() { std::cout << "destructor\n"; }
//
//    Object(const Object& object) { std::cout << "copy\n"; }
//    Object& operator = (const Object& object) { std::cout << "assignment\n"; return *this; }
//};

namespace nu
{
    struct Color4
    {
        float r, g, b, a;
    };
}
struct Vertex
{
    Vector3 position;
    Color4 color;
};

std::vector<Vertex> vertices =
{
    Vertex{ Vector3{ -1.0f, -1.0f, 0.0f}, Color4{1,0,0,1}}, // Bottom-Left
    Vertex{  Vector3{1.0f, -1.0f, 0.0f}, Color4{0,1,0,1}}, // Bottom-Right
    Vertex{  Vector3{0.0f,  1.0f, 0.0f}, Color4{0,0,1,1}}, // Top-Middle
};

/*class ICreator
{
public:
    virtual ~ICreator() = default;
    virtual std::unique_ptr<Animal> Create() = 0;
};

template <typename T>
class Creator : public ICreator
{
public:
    std::unique_ptr<Animal> Create() override { return std::unique_ptr<T>(); }
};


std::map<std::string, std::unique_ptr<ICreator>> registry;*/

int main()
{
    SetWorkingDirectory("Assets");

    // load the json data from a file
    /*std::string buffer;
    if (ReadTextFile("data/data.json", buffer))
    {
        // show the contents of the json file (debug)
        std::cout << buffer << std::endl;

        // create json document from the json file contents
        rapidjson::Document document;
        if (json::Load("data/data.json", document))
        {
            // read the age data (int) from the json
            std::string name;
            int age;
            float speed;
            bool isAwake;
            nu::Vector2 position;
            nu::Vector3 color;

            // read the json data
            nu::json::Read(document, "name", name);
            nu::json::Read(document, "age", age);
            nu::json::Read(document, "speed", speed);
            nu::json::Read(document, "isAwake", isAwake);
            nu::json::Read(document, "position", position);
            nu::json::Read(document, "color", color);

            std::cout << name << " " << age << " " << speed << " " << isAwake << std::endl;
            std::cout << position.x << " " << position.y << std::endl;
            std::cout << color.r << " " << color.g << " " << color.b << " " << std::endl;

        }
        // read/show the data from the json file

        // show the data

    }*/




    /*Factory::Instance().Register<Object>("Object");
    //Factory::Instance().Register<Actor>("Actor");
    //Factory::Instance().Register<Player>("Player");
    //Factory::Instance().Register<Player>("Enmey");
    //Factory::Instance().Register<Player>("Bullet");


    auto actor = Factory::Instance().Create("Actor");
    std::cout << actor->IsActive() << std::endl;

    auto object = Factory::Instance().Create("Object");
    std::cout << object->IsActive() << std::endl;

    auto player = Factory::Instance().Create<Player>("Object");
    std::cout << player->IsActive() << std::endl;

    json::document_t document;
    if (json::Load("data/scene.json", document))
    {
        player->Read(document);
        std::cout << player->GetName() << std::endl;
        std::cout << player->GetTag() << std::endl;

        std::cout << player->GetTransform().rotation << std::endl;
        std::cout << player->GetSpeed() << std::endl;
    }

    return 0;*/

    /*for (size_t i = 0; i < 10; i++) std::cout << RNG() << " ";
    std::cout << std::endl;
    for (size_t i = 0; i < 10; i++) std::cout << RNG() << " ";
    std::cout << std::endl;

    SeedRandom((unsigned int)time(NULL));
    for (size_t i = 0; i < 10; i++) std::cout << rand() << " ";
    std::cout << std::endl;


    std::random_device randomDevice;
    std::cout << randomDevice.min() << std::endl;
    std::cout << randomDevice.max() << std::endl;
    std::cout << randomDevice.entropy() << std::endl;

    std::mt19937 generator(randomDevice());

    std::uniform_int_distribution<> dist(0, 20);
    for (size_t i = 0; i < 10; i++) std::cout << dist(generator) << " ";
    std::cout << std::endl;

    std::uniform_real_distribution<float> distReal(-10.f, 200.f);
    for (size_t i = 0; i < 10; i++) std::cout << distReal(generator) << " ";
    std::cout << std::endl;*/


    /*
    std::map<std::string, int> students;
    students["Aiden"] = 16;
    students["Jack"] = 17;
    students["River"] = 15;

    std::cout << students["Aiden"] << std::endl;

    // get current working directory
    std::cout << "Directory Operations:\n";
    std::cout << "Working directory: " << nu::GetWorkingDirectory() << "\n";

    // set working directory (current working directory + "Assets")
    std::cout << "Setting directory to 'Assets'...\n";
    nu::SetWorkingDirectory("Assets");
    std::cout << "New directory: " << nu::GetWorkingDirectory() << "\n\n";

    // get filenames in the working directory
    std::cout << "Files in Directory:\n";
    auto filenames = nu::GetFilesInDirectory(nu::GetWorkingDirectory());
    for (const auto& filename : filenames)
    {
        std::cout << filename << "\n";
    }
    std::cout << "\n";

    // get filename info
    if (!filenames.empty())
    {
        // get filename
        std::string str = nu::GetFilename(filenames[0]);
        std::cout << "Filename: " << str << "\n";

        // get extension
        str = nu::GetFileExtension(filenames[0]);
        std::cout << "Extension: " << str << "\n";

        // get filename no extension
        str = nu::GetFilenameNoExtension(filenames[0]);
        std::cout << "Filename No Extension: " << str << "\n\n";
    }

    // read and display text file
    std::cout << "Text File Reading:\n";
    std::string str;
    if (nu::ReadTextFile("test.txt", str))
    {
        std::cout << str << "\n";
    }

    // write to text file
    std::cout << "Text File Writing:\n";
    nu::WriteTextFile("test.txt", "Hello, World!", true);
    if (nu::ReadTextFile("test.txt", str))
    {
        std::cout << str << "\n";
    }
    */

    /*std::cout << "============odject============\n";
    {
        Object objectA;
        Object objectB(objectA);
        Object objectC;
        objectC = objectA;

    }

    std::cout << "============raw pointers============\n";
    {
        Object* objectA = new Object();
        std::cout << objectA << std::endl;
        Object* objectB = new Object(*objectA);
        std::cout << objectB << std::endl;
        Object* objectC =nullptr;
        objectC = objectA;
        std::cout << objectC << std::endl;


        delete objectA;
        delete objectB;
        //delete objectC;

    }

    std::cout << "============smart pointers============\n";
    {
        std::unique_ptr<Object> objectA = std::make_unique<Object>();
        std::cout << objectA.get() << std::endl;
        std::unique_ptr<Object> objectB;
        objectB = std::move(objectA);
        std::cout << objectB.get() << std::endl;

        objectB.reset();
    }

    return 0;*/


    /*{
        std::ifstream file("data/text.txt");
        if (file.is_open())
        {
            std::string str;
            while (std::getline(file, str))
            {
                std::cout << str << std::endl;
            }
        }
        else
        {
            std::cout << "";
        }
        file.close();
    }


    {
        std::ofstream file("data/text.txt", std::ios::app);
        if (file.is_open())
        {
            file << "Have a good day.\n";
        }
    }

    {
        std::fstream file("data/text.txt", std::ios::in | std::ios::out | std::ios::app);
        if (file.is_open())
        {
            file << "Add a line.\n";
            file.seekg(0);
            std::string str;
            while (std::getline(file, str))
            {
                std::cout << str << std::endl;
            }
        }
    }

    {
        std::string name;
        int score;
        bool isAlive;

        bool save = true;
        if (save)
        {
            name = "Aiden";
            score = 1234;
            isAlive = true;

            std::ofstream file("data/game.txt");
            if (file.is_open())
            {
                file << name << "\n";
                file << score << "\n";
                file << std::boolalpha << isAlive << "\n";

            }
        }
        bool load = true;
        if (load)
        {
            std::ifstream file("data/text.txt");
            if (file.is_open())
            {
                std::getline(file, name);

                std::string str;
                std::getline(file, str);

                score = std::stoi(str);
                file >> std::boolalpha >> isAlive;
            }
    }



    return 0;*/

    // INITALIZATION
    Engine::Get().Initialize();

    auto vb = std::make_shared<VertexBuffer>();
    vb->Create<Vertex>(vertices, Engine::Get().GetRenderer().GetGPUDevice());

    auto vshader = Resources().Get<nu::Shader>("shaders/position.vert", Engine::Get().GetRenderer(), 1);
    auto fshader = Resources().Get<nu::Shader>("shaders/color.frag", Engine::Get().GetRenderer(), 1);

    auto pipeline = std::make_shared<Pipeline>();
    pipeline->AddVertexBuffer(sizeof(Vertex));
    // color
    pipeline->AddVertexAttribute(
        1,
        SDL_GPU_VERTEXELEMENTFORMAT_FLOAT4,
        offsetof(Vertex, color));

    pipeline->Create(*vshader.get(), *fshader.get(),
        Engine::Get().GetRenderer().GetGPUDevice(),
        Engine::Get().GetRenderer().GetWindow());

    //std::unique_ptr game = std::make_unique<SpaceGame>();




    // create audio system
    FMOD::System* audio;
    FMOD::System_Create(&audio);

    void* extradriverdata = nullptr;
    audio->init(32, FMOD_INIT_NORMAL, extradriverdata);

    std::vector<FMOD::Sound*> sounds;

    FMOD::Sound* sound = nullptr;

    Engine::Get().GetAudio().AddSound("sound", "audio/whistle.mp3");

    // create texture, using shared_ptr so texture can be shared
    //std::shared_ptr<Texture> texture = std::make_shared<Texture>();
    //texture->Load("textures/spaceship_BLUE.png", Engine::Get().GetRenderer());

    float scale = 0.5f;
    Color4 color{ 0,0,0,1 };

    // MANE LOOP
    bool quit = false;
    while (!quit) 
    {

        SDL_Event event;
        while (SDL_PollEvent(&event)) 
        {
            if (event.type == SDL_EVENT_QUIT) 
            {
                quit = true;
            }
            if (event.type == SDL_EVENT_KEY_DOWN && event.key.scancode == SDL_SCANCODE_ESCAPE)
            {
                quit = true;
            }
        }

        // UPDATE
        Engine::Get().Update();
        float dt = Engine::Get().GetTime().GetDeltaTime();

        scale = sin(Engine::Get().GetTime().GetTime());
        color.r = sin(Engine::Get().GetTime().GetTime() * 10.0f) * 0.5f * 0.5f;

        // RENDER
        Engine::Get().GetRenderer().BeginFrame();

        Engine::Get().GetRenderer().SetPipeline(*pipeline);
        Engine::Get().GetRenderer().SetVertexBuffer(*vb);
        Engine::Get().GetRenderer().SetVertexUniform(0, &scale, sizeof(scale));
        Engine::Get().GetRenderer().SetFramentUniform(0, &color, sizeof(color));

        Engine::Get().GetRenderer().Draw(vb->GetVertexCount());

        Engine::Get().GetRenderer().EndFrame();
    }


    Engine::Get().Shutdown();
    
    return 0;
}


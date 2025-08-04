#pragma once
#include "QueueFamilyIndices.h"

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

const std::string MODEL_PATH = "Models/vikingroom.obj";
const std::string TEXTURE_PATH = "Textures/vikingroom.png";

class CruxGraphicsModule
{
public:
	void CruxRun();

    bool framebufferResized = false;

private:
    //MEMBER FUNCTIONS:
    void CruxInitWindow();
    void CruxInitVulkan();
    void CruxMainLoop();
    void CruxCleanupSwapChain();
    void CruxCleanup();
    void CruxRecreateSwapChain();
    void CruxCreateInstance();
    void CruxPopulateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
    void CruxSetupDebugMessenger();
    void CruxCreateSurface();
    void CruxPickPhysicalDevice();
    void CruxCreateLogicalDevice();
    void CruxCreateSwapChain();
    void CruxCreateImageViews();
    void CruxCreateRenderPass();
    void CruxCreateGraphicsPipeline();
    void CruxCreateFramebuffers();
    void CruxCreateCommandPool();
    void CruxCreateVertexBuffer();
    uint32_t CruxFindMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);
    void CruxCreateCommandBuffers();
    void CruxRecordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);
    void CruxCreateSyncObjects();
    void CruxDrawFrame();
    VkShaderModule CruxCreateShaderModule(const std::vector<char>& code);
    VkSurfaceFormatKHR CruxChooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
    VkPresentModeKHR CruxChooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
    VkExtent2D CruxChooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
    SwapChainSupportDetails CruxQuerySwapChainSupport(VkPhysicalDevice device);
    bool CruxIsDeviceSuitable(VkPhysicalDevice device);
    bool CruxCheckDeviceExtensionSupport(VkPhysicalDevice device);
    QueueFamilyIndices CruxFindQueueFamilies(VkPhysicalDevice device);
    std::vector<const char*> CruxGetRequiredExtensions();
    bool CruxCheckValidationLayerSupport();
    void CruxCreateBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer,
        VkDeviceMemory& bufferMemory);
    void CruxCopyBuffer(VkBuffer SrcBuffer, VkBuffer DstBuffer, VkDeviceSize size);
    void CruxCreateIndexBuffer();
    void CruxCreateDescriptorSetLayout();
    void CruxCreateUniformBuffer();
    void CruxUpdateUniformBuffer(uint32_t currentImage);
    void CruxCreateDescriptorPool();
    void CruxCreateDescriptorSets();
    void CruxCreateTextureImage();
    void CruxCreateImage(uint32_t width, uint32_t height, VkFormat format,
        VkImageTiling tiling, VkImageUsageFlags usage,
        VkMemoryPropertyFlags properties, VkImage& image,
        VkDeviceMemory& imageMemory);
    VkCommandBuffer CruxBeginSingleTimeCommands();
    void CruxEndSingleTimeCommands(VkCommandBuffer CommandBuffer);
    void CruxCopyBuffer();
    void CruxTransitionImageLayout(VkImage image, VkFormat format, VkImageLayout oldLayout, VkImageLayout newLayout);
    void CruxCopyBufferToImage(VkBuffer buffer, VkImage image, uint32_t width, uint32_t height);
    void CruxCreateTextureImageView();
    VkImageView CruxCreateImageView(VkImage Image, VkFormat format, VkImageAspectFlags aspectFlags);
    void CruxCreateTextureSampler();
    void CruxCreateDepthResources();
    VkFormat CruxFindSupportedFormat(const std::vector<VkFormat>& candidates, VkImageTiling tiling, VkFormatFeatureFlags features);
    VkFormat CruxFindDepthFormat();
    bool CruxHasStencilComponent(VkFormat format);
    void CruxLoadModel();

    //DATA MEMBERS:
    GLFWwindow* window;
    const int WindowWidth = 980;
    const int WindowHeight = 720;

    VkInstance instance;
    VkDebugUtilsMessengerEXT debugMessenger;
    VkSurfaceKHR surface;

    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    VkDevice device;

    VkQueue graphicsQueue;
    VkQueue presentQueue;

    VkSwapchainKHR swapChain;
    std::vector<VkImage> swapChainImages;
    VkFormat swapChainImageFormat;
    VkExtent2D swapChainExtent;
    std::vector<VkImageView> swapChainImageViews;
    std::vector<VkFramebuffer> swapChainFramebuffers;

    VkRenderPass renderPass;
    VkDescriptorSetLayout descriptorSetLayout;
    VkDescriptorPool descriptorPool;
    VkPipelineLayout pipelineLayout;
    VkPipeline graphicsPipeline;

    VkCommandPool commandPool;

    std::vector<Vertex> vertices;
    std::vector<uint32_t> indices;
    VkBuffer vertexBuffer;
    VkDeviceMemory vertexBufferMemory;
    VkBuffer indexBuffer;
    VkDeviceMemory indexBufferMemory;
    VkImage textureImage;
    VkDeviceMemory textureImageMemory;
    VkImageView textureImageView;
    VkSampler textureSampler;
    VkImage depthImage;
    VkDeviceMemory depthImageMemory;
    VkImageView depthImageView;

    std::vector<VkBuffer> uniformBuffer;
    std::vector<VkDeviceMemory> uniformBufferMemory;
    std::vector<void*> uniformBuffersMappped;
    std::vector<VkDescriptorSet> descriptorSets;

    std::vector<VkCommandBuffer> commandBuffers;

    std::vector<VkSemaphore> imageAvailableSemaphores;
    std::vector<VkSemaphore> renderFinishedSemaphores;
    std::vector<VkFence> inFlightFences;
    uint32_t currentFrame = 0;
    bool printSwitch = true;
};


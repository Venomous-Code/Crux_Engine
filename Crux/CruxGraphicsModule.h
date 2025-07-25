#pragma once
#include "QueueFamilyIndices.h"

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
    VkPipelineLayout pipelineLayout;
    VkPipeline graphicsPipeline;

    VkCommandPool commandPool;

    VkBuffer vertexBuffer;
    VkDeviceMemory vertexBufferMemory;

    std::vector<VkCommandBuffer> commandBuffers;

    std::vector<VkSemaphore> imageAvailableSemaphores;
    std::vector<VkSemaphore> renderFinishedSemaphores;
    std::vector<VkFence> inFlightFences;
    uint32_t currentFrame = 0;
    bool printSwitch = true;
};


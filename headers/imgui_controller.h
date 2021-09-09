#pragma once
#ifndef IMGUICLASS_H
#define IMGUICLASS_H

#include"imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

class ImGui_controller {

private:
	ImGui_controller() {}

public:
	static void Setup(GLFWwindow* window) {
		//imgui begin
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		ImGui::StyleColorsDark();
		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init("#version 330");
	}
	//ImGui_controller(GLFWwindow* window) {
	//	//imgui begin
	//	IMGUI_CHECKVERSION();
	//	ImGui::CreateContext();
	//	ImGuiIO& io = ImGui::GetIO(); (void)io;
	//	ImGui::StyleColorsDark();
	//	ImGui_ImplGlfw_InitForOpenGL(window, true);
	//	ImGui_ImplOpenGL3_Init("#version 330");
	//}

	static void NewFrame() {
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	static void Render() {
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	static void Shutdown() {
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}

	static void PointLightGUI(PointLight& pointLight, bool angleRadiusMode = false) {
		ImGui::Text("Point light");
		/*float yaw = 0.0f;
		float pitch = 0.0f;
		float radius = 45.0f;
		

		if (angleRadiusMode == true) {
			ImGui::SliderFloat("radius", &radius, 0.0f, 10.0f);
			ImGui::SliderFloat("yaw", &yaw, -2.0f * PI, 2.0f * PI);
			ImGui::SliderFloat("pitch", &pitch, -2.0f * PI, 4.0f * PI);

			pointLight.position = glm::vec3(
				std::cos(pitch) * std::cos(yaw),
				std::cos(pitch) * std::sin(yaw),
				std::sin(pitch)
			);
		}
		else{*/
			ImGui::SliderFloat3("position##point", glm::value_ptr(pointLight.position), -10.0f, 10.0f);
		//}
		ImGui::SliderFloat("intensity", &pointLight.intensity, 0.0f, 100.0f);
		ImGui::ColorEdit3("ambient##point", glm::value_ptr(pointLight.ambient));
		ImGui::ColorEdit3("diffuse##point", glm::value_ptr(pointLight.diffuse));
		ImGui::ColorEdit3("specular##point", glm::value_ptr(pointLight.specular));
	}

};
#endif
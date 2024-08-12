#include "strategy.h"
#include <stdio.h>

// Navigation strategy implementations
void quickRouteStrategy(Coordinates destination) {
    printf("Navigating to destination using the Quick Route strategy to (%f, %f)\n", destination.latitude, destination.longitude);
}

void convenientRouteStrategy(Coordinates destination) {
    printf("Navigating to destination using the Convenient Route strategy to (%f, %f)\n", destination.latitude, destination.longitude);
}

void minimumFareRouteStrategy(Coordinates destination) {
    printf("Navigating to destination using the Minimum Fare Route strategy to (%f, %f)\n", destination.latitude, destination.longitude);
}

static NavigationStrategy currentNavigationStrategy = quickRouteStrategy;

void setNavigationStrategy(NavigationStrategy strategy) {
    currentNavigationStrategy = strategy;
}

void navigateTo(Coordinates destination) {
    if (currentNavigationStrategy) {
        currentNavigationStrategy(destination);
    } else {
        printf("No navigation strategy set.\n");
    }
}

void navigatehandle() {
    int strategyChoice;
    Coordinates destination;
    int values[1];
    // 사용자로부터 좌표 입력 받기
    printf("Enter destination coordinates:\n");
    printf("Latitude: ");
    scanf("%lf", &destination.latitude);
    values[0]=destination.latitude;
    printf("Longitude: ");
    scanf("%lf", &destination.longitude);
    values[1]=destination.longitude;
    writeOrUpdateValueToFile("NAVIGATION", values, 2);  // 배열의 주소를 전달
    // 사용자로부터 네비게이션 전략 선택 받기
    printf("Select navigation strategy:\n");
    printf("1. Quick Route\n");
    printf("2. Convenient Route\n");
    printf("3. Minimum Fare Route\n");
    printf("Enter choice (1-3): ");
    scanf("%d", &strategyChoice);

    // 선택한 전략에 따라 네비게이션 전략 설정
    switch (strategyChoice) {
        case 1:
            setNavigationStrategy(quickRouteStrategy);
            break;
        case 2:
            setNavigationStrategy(convenientRouteStrategy);
            break;
        case 3:
            setNavigationStrategy(minimumFareRouteStrategy);
            break;
        default:
            printf("Invalid choice. Using Quick Route as default.\n");
            setNavigationStrategy(quickRouteStrategy);
            break;
    }

    // 설정된 전략으로 네비게이션 실행
    navigateTo(destination);
}
